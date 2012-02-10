# include <stdio.h>
# include <errno.h>
# include <string.h>

# include "java_class.h"

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

	printf("\ncp: %p\n", class->constant_pool);
	unsigned int i;
	for(i = 0; i < class->constant_pool_count-1; i++)
	{
		printf("[%u] type: %hhu\n", i, class->constant_pool[i]->tag);
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
	}

	java_class_free(class);
	
	return 0;
}
