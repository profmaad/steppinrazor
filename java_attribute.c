# include <string.h>
# include <stdarg.h>
# include <errno.h>

# include "binary_helpers.h"
# include "java_attribute.h"

bool java_attribute_skip(FILE *input, bool no_index)
{
	uint32_t length = 0;
	long initial_pos = ftell(input);

	if(!(
		   ( no_index || (fseek(input, 2, SEEK_CUR) == 0)) &&
		   fread_uint32(input, &length) &&
		   (fseek(input, length, SEEK_CUR) == 0)
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
		if(!java_attribute_skip(input, false))
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

		name_index -= 1;

		if(cp[name_index] &&
		   cp[name_index]->utf8 &&
		   (cp[name_index]->utf8->length == name_len) &&
		   (strncmp((const char*)cp[name_index]->utf8->bytes, name, name_len) == 0))
		{
			*attributes_left = attributes_count-1-i;
			return true;
		}
		else
		{
			if(!java_attribute_skip(input, true)) { break; }
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
long java_attribute_findmultiple(FILE *input, uint16_t attributes_count, java_constant_pool_entry **cp, ...)
{
	long initial_pos = ftell(input);
	long end_pos = 0;

	va_list params;
	unsigned int params_count = 0;
	va_start(params, cp);
	void *tmp_ptr = NULL;
	while((tmp_ptr = va_arg(params, void*)) != NULL)
	{
		params_count++;
	}
	params_count /= 2;

	long *positions[params_count];
	const char *names[params_count];
	size_t name_lengths[params_count];

	va_start(params, cp);
	unsigned int i;
	for(i = 0; i < params_count; i++)
	{
		names[i] = va_arg(params, const char*);
		positions[i] = va_arg(params, long*);
		name_lengths[i] = strlen(names[i]);		
	}
	va_end(params);

	uint16_t name_index = 0;
	unsigned int j;
	for(i = 0; i < attributes_count; i++)
	{
		if(!fread_uint16(input, &name_index)) { end_pos = -1; break; }

		name_index -= 1;
		if(cp[name_index] && cp[name_index]->utf8)
		{			
			for(j = 0; j < params_count; j++)
			{
				if((cp[name_index]->utf8->length == name_lengths[j]) &&
				   (strncmp((const char*)cp[name_index]->utf8->bytes, names[j], name_lengths[j]) == 0))
				{
					*(positions[j]) = ftell(input);
				}
			}
		}
		
		if(!java_attribute_skip(input, true)) { end_pos = -1; printf("skip\n");  break; }
	}

	if(end_pos < 0)
	{
		fseek(input, SEEK_SET, initial_pos);
		return -1;
	}

	return ftell(input);
}
