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
	
	uint8_t value_tag;
	union
	{
		uint32_t int_value;
		uint64_t long_value;
		float float_value;
		double double_value;
	};
} java_field;

bool java_fields_parse(FILE *input, uint16_t *fields_count, java_field ***fields, java_constant_pool_entry **cp);
void java_fields_free(uint16_t fields_count, java_field **fields);

# endif /*STEPPINRAZOR_JAVA_FIELD_H*/
