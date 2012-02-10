# ifndef STEPPINRAZOR_JAVA_CLASS_H
# define STEPPINRAZOR_JAVA_CLASS_H

# include <stdint.h>

# include "java_constant_pool.h"
# include "java_field.h"

struct java_method;
typedef struct java_method java_method;

typedef struct java_class
{
	uint16_t minor_version;
	uint16_t major_version;

	uint16_t constant_pool_count;
	java_constant_pool_entry** constant_pool;

	uint16_t access_flags;

	uint16_t this_class;
	uint16_t super_class;
	
	uint16_t interfaces_count;
	uint16_t* interfaces;

	uint16_t fields_count;
	java_field** fields;

	uint16_t methods_count;
	java_method** methods;
} java_class;

const java_class* load_class(FILE *input);

void java_class_free(const java_class *class);

# endif /*STEPPINRAZOR_JAVA_CLASS_H*/
