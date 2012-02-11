# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include "binary_helpers.h"
# include "java_class.h"
# include "java_constant_pool.h"
# include "java_field.h"

# define JAVA_CLASSFILE_MAGIC_VALUE "\xCA\xFE\xBA\xBE"

bool check_magic_value(FILE *input)
{
	char buffer[4];
	
	if(fread((void*)buffer, 1, 4, input) != 4) { return false; }
	
	return (strncmp(buffer, JAVA_CLASSFILE_MAGIC_VALUE, 4) == 0);
}

bool java_class_version_parse(FILE *input, java_class *class)
{       
	return
		fread_uint16(input, &(class->minor_version)) &&
		fread_uint16(input, &(class->major_version))
		;
}
bool java_class_access_flags_parse(FILE *input, java_class *class)
{
	return fread_uint16(input, &(class->access_flags));		
}
bool java_class_classrefs_parse(FILE *input, java_class *class)
{
	return
		fread_uint16(input, &(class->this_class)) &&
		fread_uint16(input, &(class->super_class))
		;
}
bool java_class_interfaces_parse(FILE *input, java_class *class)
{
	if(!fread_uint16(input, &(class->interfaces_count))) { return false; }

	class->interfaces = (uint16_t*)malloc(sizeof(uint16_t)*class->interfaces_count);
	if(!class->interfaces) { return false; }

	int i;
	for(i = 0; i < class->interfaces_count; i++)
	{
		if(!fread_uint16(input, &(class->interfaces[i++]))) { return false; }
	}

	return true;
}

bool parse_classfile(FILE *input, java_class *class)
{
	return
		java_class_version_parse(input, class) &&
		java_constant_pool_parse(input, &(class->constant_pool_count), &(class->constant_pool)) &&
		java_class_access_flags_parse(input, class) &&
		java_class_classrefs_parse(input, class) &&
		java_class_interfaces_parse(input, class) &&
		java_fields_parse(input, &(class->fields_count), &(class->fields), class->constant_pool)
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

	if(nonconst_class->constant_pool) { java_constant_pool_free(nonconst_class->constant_pool_count, nonconst_class->constant_pool); }
	free(nonconst_class->constant_pool);
	
	free(nonconst_class->interfaces);

	if(nonconst_class->fields) { java_fields_free(nonconst_class->fields_count, nonconst_class->fields); }
	free(nonconst_class->fields);
	
	free(nonconst_class);
}
