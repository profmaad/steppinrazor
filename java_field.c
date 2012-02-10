# include <stdlib.h>

# include "binary_helpers.h"
# include "java_attribute.h"
# include "java_field.h"

bool java_field_parse(FILE *input, java_field *field)
{
	if(!(
		   fread_uint16(input, &(field->access_flags)) &&
		   fread_uint16(input, &(field->name_index)) &&
		   fread_uint16(input, &(field->descriptor_index)) &&
		   fread_uint16(input, &(field->attributes_count)) &&
		   java_attribute_skipall(input, field->attributes_count)
		   ))
	{ return false; }

	return true;
}

bool java_fields_parse(FILE *input, uint16_t *fields_count, java_field ***fields)
{
	if(!fread_uint16(input, fields_count)) { return false; }

	*fields = (java_field**)malloc(sizeof(java_field*) * *fields_count);
	if(!*fields) { return false; }
  
	int i;
	for(i = 0; i < *fields_count; i++)
	{
		java_field *field = (java_field*)malloc(sizeof(java_field));
		if(!field) { return false; }

		if(!java_field_parse(input, field)) { return false; }

		(*fields)[i] = field;
	}

	return true;	
}
