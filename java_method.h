# ifndef STEPPINRAZOR_JAVA_METHOD_H
# define STEPPINRAZOR_JAVA_METHOD_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct java_method
{
	uint16_t access_flags;
	
	uint16_t name_index;
	uint16_t descriptor_index;

	uint16_t attributes_count;
	
} java_method;

bool java_methods_parse(FILE *input, uint16_t *methods_count, java_method ***methods, java_constant_pool_entry **cp);
void java_methods_free(uint16_t methods_count, java_method **methods);

# endif /*STEPPINRAZOR_JAVA_METHOD_H*/
