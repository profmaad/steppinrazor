# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "binary_helpers.h"
# include "java_class.h"
# include "java_constant_pool.h"

# define JAVA_CLASSFILE_MAGIC_VALUE "\xCA\xFE\xBA\xBE"

bool check_magic_value(FILE *input)
{
	char buffer[4];
	
	if(fread((void*)buffer, 1, 4, input) != 4) { return false; }
	
	return (strncmp(buffer, JAVA_CLASSFILE_MAGIC_VALUE, 4) == 0);
}

bool parse_version_informaton(FILE *input, java_class *class)
{       
	return
		fread_uint16(input, &(class->minor_version)) &&
		fread_uint16(input, &(class->major_version))
		;
}

bool parse_constant_pool(FILE *input, java_class *class)
{
	if(!fread_uint16(input, &(class->constant_pool_count))) { return false; }

	class->constant_pool = (java_constant_pool_entry**)malloc(sizeof(java_constant_pool_entry*) * class->constant_pool_count-1);
	if(!class->constant_pool) { return false; }
  
	return java_constant_pool_parse(input, class->constant_pool_count, class->constant_pool);
}

bool parse_classfile(FILE *input, java_class *class)
{
	return
		parse_version_informaton(input, class) &&
		parse_constant_pool(input, class)
		;
}

const java_class* load_class(FILE *input)
{
	java_class *class = NULL;

	if(!check_magic_value(input)) { return NULL; }

	class = (java_class*)malloc(sizeof(java_class));
	if(!class) { return NULL; }
	
	if(!parse_classfile(input, class))
	{
		java_class_free(class);
		return NULL;
	}

	return class;
}

void java_class_free(const java_class *class)
{
	java_class *nonconst_class = (java_class*)class;

	free(nonconst_class);
}
