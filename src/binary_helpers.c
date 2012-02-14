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

bool fread_float(FILE *input, float *value)
{
	uint8_t buffer[4];

	if(fread(buffer, 1, 4, input) != 4) { return false; }

	uint8_t *value_ptr = (uint8_t*)value;
	*value_ptr++ = buffer[3];
	*value_ptr++ = buffer[2];
	*value_ptr++ = buffer[1];
	*value_ptr++ = buffer[0];

	return true;
}
bool fread_double(FILE *input, double *value)
{
	uint8_t buffer[8];

	if(fread(buffer, 1, 8, input) != 8) { return false; }

	uint8_t *value_ptr = (uint8_t*)value;
	*value_ptr++ = buffer[7];
	*value_ptr++ = buffer[6];
	*value_ptr++ = buffer[5];
	*value_ptr++ = buffer[4];
	*value_ptr++ = buffer[3];
	*value_ptr++ = buffer[2];
	*value_ptr++ = buffer[1];
	*value_ptr++ = buffer[0];

	return true;
}
