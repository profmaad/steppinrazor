# ifndef STEPPINRAZOR_JAVA_FIELD_H
# define STEPPINRAZOR_JAVA_FIELD_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct java_field
{
	uint16_t access_flags;
	
	uint16_t name_index;
	uint16_t descriptor_index;

	uint16_t attributes_count;
	
	union
	{
		uint32_t int_value;
		uint64_t long_value;
		float float_value;
		double double_value;
	};
} java_field;

bool java_field_parse(FILE *input, java_field *field);
bool java_fields_parse(FILE *input, uint16_t *fields_count, java_field ***fields);

# endif /*STEPPINRAZOR_JAVA_FIELD_H*/
