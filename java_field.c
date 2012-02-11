# include <stdlib.h>

# include "binary_helpers.h"
# include "java_attribute.h"
# include "java_constant_pool.h"
# include "java_field.h"

bool java_field_parse(FILE *input, java_field *field, java_constant_pool_entry **cp)
{
	if(!(
		   fread_uint16(input, &(field->access_flags)) &&
		   fread_uint16(input, &(field->name_index)) &&
		   fread_uint16(input, &(field->descriptor_index)) &&
		   fread_uint16(input, &(field->attributes_count))
		   ))
	{ return false; }

	uint16_t cp_index;
	uint16_t attributes_left = field->attributes_count;
	if(java_attribute_find(input, field->attributes_count, "ConstantValue", cp, &attributes_left))
	{		
		if(!(
			   (fseek(input, 4, SEEK_CUR) == 0) &&
			   fread_uint16(input, &cp_index) &&
			   cp[cp_index]
			   ))
		{
			return false;
		}

		field->value_tag = cp[cp_index]->tag;

		switch(cp[cp_index]->tag)
		{
		case JAVA_CP_ENTRY_INTEGER:
			field->int_value = cp[cp_index]->const_integer->value;
			break;
		case JAVA_CP_ENTRY_FLOAT:
			field->float_value = cp[cp_index]->const_float->value;
			break;
		case JAVA_CP_ENTRY_LONG:
			field->long_value = cp[cp_index]->const_long->value;
			break;
		case JAVA_CP_ENTRY_DOUBLE:
			field->double_value = cp[cp_index]->const_double->value;
			break;
		default:
			return false;
		}
	}

	java_attribute_skipall(input, attributes_left);

	return true;
}

bool java_fields_parse(FILE *input, uint16_t *fields_count, java_field ***fields, java_constant_pool_entry **cp)
{
	if(!fread_uint16(input, fields_count)) { return false; }

	*fields = (java_field**)malloc(sizeof(java_field*) * *fields_count);
	if(!*fields) { return false; }
  
	int i;
	for(i = 0; i < *fields_count; i++)
	{
		java_field *field = (java_field*)malloc(sizeof(java_field));
		if(!field) { return false; }

		if(!java_field_parse(input, field, cp)) { return false; }

		(*fields)[i] = field;
	}

	return true;	
}
void java_fields_free(uint16_t fields_count, java_field **fields)
{
	int i;
	for(i = 0; i < fields_count; i++)
	{
		if(fields[i]) { free(fields[i]); }
	}
}
