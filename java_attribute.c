# include "binary_helpers.h"
# include "java_attribute.h"

bool java_attribute_skip(FILE *input)
{
	uint32_t length = 0;
	long initial_pos = ftell(input);

	if(!(
		   (fseek(input, 2, SEEK_CUR) == 0) &&
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
		if(!java_attribute_skip(input))
		{
			fseek(input, initial_pos, SEEK_SET);
			return false;
		}
	}

	return true;
}
