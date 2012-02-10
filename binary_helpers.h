# ifndef STEPPINRAZOR_BINARY_HELPERS_H
# define STEPPINRAZOR_BINARY_HELPERS_H

# include <stdint.h>
# include <stdio.h>
# include <stdbool.h>

bool fread_uint8(FILE *input, uint8_t *value);
bool fread_uint16(FILE *input, uint16_t *value);
bool fread_uint32(FILE *input, uint32_t *value);
bool fread_uint64(FILE *input, uint64_t *value);

bool fread_float(FILE *input, float *value);
bool fread_double(FILE *input, double *value);

# endif /*STEPPINRAZOR_BINARY_HELPERS_H*/
