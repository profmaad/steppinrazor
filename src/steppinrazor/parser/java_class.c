# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

# include <steppinrazor/common/binary_helpers.h>
# include <steppinrazor/parser/java_class.h>
# include <steppinrazor/parser/java_constant_pool.h>
# include <steppinrazor/parser/java_field.h>
# include <steppinrazor/parser/java_attribute.h>

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
		if(!fread_uint16(input, &(class->interfaces[i]))) { return false; }
	}

	return true;
}

bool java_class_innerclasses_parse(FILE *input, java_class *class)
{
	if(!fread_uint16(input, &(class->inner_classes_count))) { return false; }

	class->inner_classes = (java_inner_class**)malloc(sizeof(java_inner_class*) * class->inner_classes_count);
	if(!class->inner_classes) { return false; }

	int i;
	for(i = 0; i < class->inner_classes_count; i++)
	{
		java_inner_class *inner_class = (java_inner_class*)malloc(sizeof(java_inner_class));
		if(!inner_class) { return false; }

		if(!(
			   fread_uint16(input, &(inner_class->inner_class_info_index)) &&
			   fread_uint16(input, &(inner_class->outer_class_info_index)) &&
			   fread_uint16(input, &(inner_class->inner_name_index)) &&
			   fread_uint16(input, &(inner_class->access_flags))
			   ))
		{ return false; }

		class->inner_classes[i] = inner_class;
	}

	return true;
}
bool java_class_attributes_parse(FILE *input, java_class *class)
{
	uint16_t attributes_count = 0;
	long synthetic_attr_pos = -1;
	long innerclasses_attr_pos = -1;

	if(!fread_uint16(input, &attributes_count)) { return false; }

	if(java_attribute_findmultiple(input, attributes_count, class->constant_pool, "Synthetic", &synthetic_attr_pos, "InnerClasses", &innerclasses_attr_pos, NULL) < 0)
	{ return false; }

	if(synthetic_attr_pos >= 0) { class->synthetic = true; }

	if(innerclasses_attr_pos >= 0 &&
	   !(
		   (fseek(input, innerclasses_attr_pos+4, SEEK_SET) == 0) &&
		   java_class_innerclasses_parse(input, class)
		   )
		)
	{
		return false;
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
		java_fields_parse(input, &(class->fields_count), &(class->fields), class->constant_pool) &&
		java_methods_parse(input, &(class->methods_count), &(class->methods), class->constant_pool) &&
		java_class_attributes_parse(input, class)
		;
}

const java_class* load_class(FILE *input)
{
	java_class *class = NULL;

	if(!check_magic_value(input)) { return NULL; }

	class = (java_class*)malloc(sizeof(java_class));
	if(!class) { return NULL; }
	
	class->synthetic = false;

	if(!parse_classfile(input, class))
	{
       		java_class_free(class);
		return NULL;
	}

	return class;
}

void java_class_innerclasses_free(uint16_t inner_classes_count, java_inner_class **inner_classes)
{
	int i;
	for(i = 0; i < inner_classes_count; i++)
	{
		if(inner_classes[i]) { free(inner_classes[i]); }
	}
}
void java_class_free(const java_class *class)
{
	java_class *nonconst_class = (java_class*)class;

	if(nonconst_class->constant_pool) { java_constant_pool_free(nonconst_class->constant_pool_count, nonconst_class->constant_pool); }
	free(nonconst_class->constant_pool);

	free(nonconst_class->interfaces);

	if(nonconst_class->fields) { java_fields_free(nonconst_class->fields_count, nonconst_class->fields); }
	free(nonconst_class->fields);

	if(nonconst_class->methods) { java_methods_free(nonconst_class->methods_count, nonconst_class->methods); }
	free(nonconst_class->methods);

	if(nonconst_class->inner_classes) { java_class_innerclasses_free(nonconst_class->inner_classes_count,  nonconst_class->inner_classes); }
	free(nonconst_class->inner_classes);
	
	free(nonconst_class);
}
