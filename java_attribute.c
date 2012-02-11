# include <string.h>

# include "binary_helpers.h"
# include "java_attribute.h"

bool java_attribute_skip(FILE *input, bool no_index)
{
	uint32_t length = 0;
	long initial_pos = ftell(input);

	if(!(
		   ( no_index || (fseek(input, 2, SEEK_CUR) == 0)) &&
		   fread_uint32(input, &length) &&
		   fseek(input, length, SEEK_CUR)
		   ))
	{
		fseek(input, initial_pos, SEEK_SET);
		return false;
	}
	
	return true;
}
bool java_attribute_skipall(FILE *input, uint16_t attributes_count)
{
	long initial_pos = ftell(input);

	uint16_t i;
	for(i = 0; i < attributes_count; i++)
	{
		if(!java_attribute_skip(input, true))
		{
			fseek(input, initial_pos, SEEK_SET);
			return false;
		}
	}

	return true;
}

bool java_attribute_find(FILE *input, uint16_t attributes_count, const char *name, java_constant_pool_entry **cp, uint16_t *attributes_left)
{
	long initial_pos = ftell(input);
	long attr_pos = -1;
	size_t name_len = strlen(name);

	uint16_t i;
	uint16_t name_index;
	for(i = 0; i < attributes_count; i++)
	{
		if(!fread_uint16(input, &name_index)) { break; }

		if(cp[name_index] &&
		   cp[name_index]->utf8 &&
		   (cp[name_index]->utf8->length == name_len) &&
		   strncmp((const char*)cp[name_index]->utf8->bytes, name, name_len))
		{
			*attributes_left = attributes_count-1-i;
			return true;
		}
		else
		{
			if(!java_attribute_skip(input, false)) { break; }
		}
	}

	if(attr_pos < 0)
	{
		fseek(input, initial_pos, SEEK_SET);
		return false;
	}

	fseek(input, attr_pos, SEEK_SET);

	return true;
}
