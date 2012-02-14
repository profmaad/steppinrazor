# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <stdlib.h>

# include <arpa/inet.h>

# include "jvm.h"

# include "java_class.h"

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <inputfile>\n", argv[0]);
		return 1;
	}

	const char *input_filename = argv[1];

	FILE *input = NULL;

	input = fopen(input_filename, "rb");
	if(!input)
	{
		fprintf(stderr, "Failed to open input file: %s\n", strerror(errno));
		return 1;
	}

	const java_class *class = load_class(input);
	if(!class)
	{
		fprintf(stderr, "Failed to parse class definition\n");
		return 2;
	}
	if(fclose(input) != 0)
	{
		fprintf(stderr, "Failed to close input file: %s\n", strerror(errno));
		return 1;
	}

	uint32_t i;
	java_method *method = NULL;
	for(i = 0; i < class->methods_count; i++)
	{
		if(class->constant_pool[class->methods[i]->name_index]->utf8->length == 4 && (strncmp((const char*)class->constant_pool[class->methods[i]->name_index]->utf8->bytes, "main", 4) == 0))
		{
			method = class->methods[i];
			break;
		}
	}
	if(!method)
	{
		fprintf(stderr, "No main method found\n");
		return 3;
	}

	const char *descriptor = strndup((const char*)class->constant_pool[method->descriptor_index]->utf8->bytes, class->constant_pool[method->descriptor_index]->utf8->length);

	descriptor = strchr(descriptor, ')');
	
	const char return_type = descriptor[1];

	printf("max stack: %hu\n", method->code->max_stack);
	printf("max locals: %hu\n", method->code->max_locals);
	printf("return type: %c\n", return_type);
	printf("bytecode length: %u\n", method->code->code_length);

	for(i = 0; i < method->code->code_length; i++)
	{
		printf("%02hhx ", method->code->bytecode[i]);
		if((i+1) % 8 == 0) { printf("\n"); }
	}
	printf("\n");
	
	switch(return_type)
	{
	case 'Z':
		printf("result: %hhu\n", (uint8_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;
	case 'B':
		printf("result: %hhd\n", (int8_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;
	case 'C':
		printf("result: %hhu\n", (uint8_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;
	case 'S':
		printf("result: %hd\n", (int16_t)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;
	case 'I':
		printf("result: %d\n", (int)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;
	case 'J':
		printf("result: %ld\n", (long)run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;      
	case 'F':
		printf("result: %f\n", run_method_float(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;      
	case 'D':
		printf("result: %f\n", run_method_double(method->code->max_stack, method->code->max_locals, method->code->bytecode));
		break;
	case 'L':
		printf("result: %p\n", run_method(method->code->max_stack, method->code->max_locals, method->code->bytecode));
	}

	java_class_free(class);

	return 0;
}
