# include <stdio.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>

# include <steppinrazor/parser/java_class.h>
# include <steppinrazor/java_runtime_class.h>

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <.class file>\n", argv[0]);
		return 1;
	}

	const char *input_filename = argv[1];

	FILE *input = fopen(input_filename, "rb");
	if(!input)
	{
		fprintf(stderr, "Failed to open class file: %s\n", strerror(errno));
		return 1;
	}

	const java_class *class = load_class(input);
	fclose(input);
	if(!class)
	{
		fprintf(stderr, "Failed to load class\n");
		return 2;
	}
	printf("class file version: %hu.%hu\n", class->major_version, class->minor_version);
	if(class->synthetic) { printf("\tis synthetic\n"); }

	printf("\ncp: %p\n", class->constant_pool);
	unsigned int i;
	for(i = 1; i < class->constant_pool_count; i++)
	{
		if(class->constant_pool[i])
		{
			printf("[%u] type: %hhu\n", i, class->constant_pool[i]->tag);
		}
	}

	printf("\ninterfaces (%hu): ", class->interfaces_count);
	for(i = 0; i < class->interfaces_count; i++)
	{
		printf("%hu, ", class->interfaces[i]);
	}
	printf("\n");

	printf("\nfields (%hu): \n", class->fields_count);
	for(i = 0; i < class->fields_count; i++)
	{
		printf("%hu, %hu\n", class->fields[i]->name_index, class->fields[i]->descriptor_index);
		if(class->fields[i]->synthetic) { printf("\tis synthetic\n"); }
		if(class->fields[i]->value_tag > 0)
		{
			printf("\t value(%hhu): ", class->fields[i]->value_tag);
			switch(class->fields[i]->value_tag)
			{
			case JAVA_CP_ENTRY_INTEGER:
				printf("%d\n", class->fields[i]->int_value);
				break;
			case JAVA_CP_ENTRY_FLOAT:
				printf("%f\n", class->fields[i]->float_value);
				break;
			case JAVA_CP_ENTRY_LONG:
				printf("%ld\n", class->fields[i]->long_value);
				break;
			case JAVA_CP_ENTRY_DOUBLE:
				printf("%f\n", class->fields[i]->double_value);
				break;
			}
		}
	}

	printf("\nmethods (%hu): \n", class->methods_count);
	for(i = 0; i < class->methods_count; i++)
	{
		printf("%hu, %hu\n", class->methods[i]->name_index, class->methods[i]->descriptor_index);

		if(class->methods[i]->code)
		{
			printf("\tcode: %hu, %hu, %u, %hu\n", class->methods[i]->code->max_stack, class->methods[i]->code->max_locals, class->methods[i]->code->code_length, class->methods[i]->code->exception_handlers_count);
		}
		if(class->methods[i]->synthetic) { printf("\tis synthetic\n"); }
		if(class->methods[i]->exceptions)
		{
			printf("\texceptions: ");
			int j;
			for(j = 0; j < class->methods[i]->exceptions_count; j++)
			{
				printf("%hu, ", class->methods[i]->exceptions[j]);
			}
			printf("\n");
		}
	}

	if(class->inner_classes)
	{
		printf("\ninner classes (%hu): \n", class->inner_classes_count);
		for(i = 0; i < class->inner_classes_count; i++)
		{
			printf("%hu, %hu, %hu\n", class->inner_classes[i]->inner_class_info_index, class->inner_classes[i]->outer_class_info_index, class->inner_classes[i]->inner_name_index);
		}
	}

	java_runtime_class *rt_class = (java_runtime_class*)malloc(sizeof(java_runtime_class));
	if(!rt_class)
	{
		fprintf(stderr, "failed to allocate memory for runtime class\n");
		exit(1);
	}
	if(!java_runtime_class_construct(rt_class, class))
	{
		fprintf(stderr, "failed to construct runtime class representation\n");
		exit(1);
	}

	if(rt_class->constant_pool)
	{
		printf("\nruntime cp:\n");
		for(i = 1; i < rt_class->constant_pool_count; i++)
		{
			if(rt_class->constant_pool_types[i] > 0)
			{
				printf("\t[%u] (%hhu): %p\n", i, rt_class->constant_pool_types[i], &(rt_class->constant_pool[i].string));
			}
		}
	}

	java_class_free(class);
	
	return 0;
}
