# include <endian.h>

# include "binary_helpers.h"

bool fread_uint8(FILE *input, uint8_t *value)
{
	uint8_t buffer;

	if(fread(&buffer, 1, 1, input) != 1) { return false; }

	*value = buffer;
	return true;	
}
bool fread_uint16(FILE *input, uint16_t *value)
{
	uint16_t buffer;

	if(fread(&buffer, 2, 1, input) != 1) { return false; }

	*value = be16toh(buffer);
	return true;
}
bool fread_uint32(FILE *input, uint32_t *value)
{
	uint32_t buffer;

	if(fread(&buffer, 4, 1, input) != 1) { return false; }

	*value = be32toh(buffer);
	return true;
}
bool fread_uint64(FILE *input, uint64_t *value)
{
	uint64_t buffer;

	if(fread(&buffer, 8, 1, input) != 1) { return false; }

	*value = be64toh(buffer);
	return true;
}
