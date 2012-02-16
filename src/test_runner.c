# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <stdlib.h>

# include <arpa/inet.h>

# include "jvm.h"

# include "java_class.h"

# define MAX_RESULT_SIZE 30
# define MAX_LINE_SIZE 100

const char* run_testmethod(const char *method_name, const java_class *class)
{
	uint32_t i;
	java_method *method = NULL;
	for(i = 0; i < class->methods_count; i++)
	{
		if(class->constant_pool[class->methods[i]->name_index]->utf8->length == strlen(method_name) && (strncmp((const char*)class->constant_pool[class->methods[i]->name_index]->utf8->bytes, method_name, class->constant_pool[class->methods[i]->name_index]->utf8->length) == 0))
		{
			method = class->methods[i];
			break;
		}
	}
	if(!method)
	{
		fprintf(stderr, "No method '%s' found\n", method_name);
		return NULL;
	}

	const char *descriptor = strndup((const char*)class->constant_pool[method->descriptor_index]->utf8->bytes, class->constant_pool[method->descriptor_index]->utf8->length);

	descriptor = strchr(descriptor, ')');
	
	const char return_type = descriptor[1];

	char result[MAX_RESULT_SIZE];

	switch(return_type)
	{
	case 'Z':
		snprintf(result, MAX_RESULT_SIZE, "%hhu", (uint8_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;
	case 'B':
		snprintf(result, MAX_RESULT_SIZE, "%hhd", (int8_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;
	case 'C':
		snprintf(result, MAX_RESULT_SIZE, "%hhu", (uint8_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;
	case 'S':
		snprintf(result, MAX_RESULT_SIZE, "%hd", (int16_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;
	case 'I':
		snprintf(result, MAX_RESULT_SIZE, "%d", (int)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;
	case 'J':
		snprintf(result, MAX_RESULT_SIZE, "%ld", (long)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;		
	case 'F':
		snprintf(result, MAX_RESULT_SIZE, "%0.2f", run_method_float(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;      
	case 'D':
		snprintf(result, MAX_RESULT_SIZE, "%0.2f", run_method_double(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
		break;
	case 'L':
		snprintf(result, MAX_RESULT_SIZE, "%p", run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode, class->runtime_cp));
	}

	return strndup(result, MAX_RESULT_SIZE);
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <testgroup>\n", argv[0]);
		return 1;
	}

	char *class_filename = (char*)malloc(strlen(argv[1])+7); // base name + ".class\0"
	char *spec_filename = (char*)malloc(strlen(argv[1])+10); // base name + ".testspec\0"
	if(!class_filename || !spec_filename)
	{
		fprintf(stderr, "failed to allocate memory\n");
		return 1;
	}
	strcpy(class_filename, argv[1]);
	strcat(class_filename, ".class");
	strcpy(spec_filename, argv[1]);
	strcat(spec_filename, ".testspec");

	FILE *class_input = NULL;
	FILE *spec_input = NULL;

	class_input = fopen(class_filename, "rb");
	if(!class_input)
	{
		fprintf(stderr, "Failed to open class file '%s': %s\n", class_filename, strerror(errno));
		return 1;
	}
	spec_input = fopen(spec_filename, "rb");
	if(!spec_input)
	{
		fprintf(stderr, "Failed to open testspec file '%s': %s\n", spec_filename, strerror(errno));
		return 1;
	}

	const java_class *class = load_class(class_input);
	if(!class)
	{
		fprintf(stderr, "Failed to parse class definition\n");
		return 1;
	}
	if(fclose(class_input) != 0)
	{
		fprintf(stderr, "Failed to close class file '%s': %s\n", class_filename, strerror(errno));
		return 1;
	}

	char line_buffer[MAX_LINE_SIZE];
	unsigned int failed_testcases = 0;
	unsigned int total_testcases = 0;
	
	while(fgets(line_buffer, MAX_LINE_SIZE, spec_input) != NULL)
	{
		if(!strchr(line_buffer, '\n'))
		{
			fprintf(stderr, "Failed to read complete line from specfile (maybe missing a newline at the end of file?)\n");
			return 1;
		}
		line_buffer[strlen(line_buffer)-1] = '\0';

		char *expected_result = strchr(line_buffer, ' ');
		if(!expected_result)
		{
			fprintf(stderr, "Malformed line in testspec (missing space), skipping: '%s'\n", line_buffer);
			continue;
		}

		size_t space_index = expected_result-line_buffer;
		expected_result += 1;

		char *method_name = strndup(line_buffer, space_index);
		if(!method_name)
		{
			fprintf(stderr, "Failed to extract method name: %s", strerror(errno));
			continue;
		}

		total_testcases++;
		printf("Running '%s'\t", method_name);
		const char *actual_result = run_testmethod(method_name, class);
		
		if((strlen(actual_result) != strlen(expected_result)) || strcmp(actual_result, expected_result) != 0)
		{
			printf("FAILED\n");
			printf("\texpected:\t'%s'\n\tgot:\t\t'%s'\n", expected_result, actual_result);
			failed_testcases++;
		}
		else
		{
			printf("passed\n");
		}
	}

	printf("\nSummary:\n");
	printf("Testcases:\t\t%u\n", total_testcases);
	printf("\tsuccessful:\t%u\n\tfailed:\t\t%u\n", total_testcases-failed_testcases, failed_testcases);

	java_class_free(class);

	return failed_testcases;
}
