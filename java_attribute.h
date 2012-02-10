# ifndef STEPPINRAZOR_JAVA_ATTRIBUTE_H
# define STEPPINRAZOR_JAVA_ATTRIBUTE_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>

# include "java_constant_pool.h"

bool java_attribute_skip(FILE *input);
bool java_attribute_skipall(FILE *input, uint16_t attributes_count);

bool java_attribute_find(FILE *input, uint16_t attributes_count, const char *name, java_constant_pool_entry **cp);

# endif /*STEPPINRAZOR_JAVA_ATTRIBUTE_H*/
