# ifndef STEPPINRAZOR_JAVA_CLASS_H
# define STEPPINRAZOR_JAVA_CLASS_H

# include <stdint.h>
# include <stdbool.h>

# include "java_constant_pool.h"
# include "java_field.h"
# include "java_method.h"

typedef struct java_inner_class
{
	uint16_t inner_class_info_index;
	uint16_t outer_class_info_index;

	uint16_t inner_name_index;
	uint16_t access_flags;

} java_inner_class;

typedef struct java_class
{
	uint16_t minor_version;
	uint16_t major_version;

	uint16_t constant_pool_count;
	java_constant_pool_entry **constant_pool;

	uint16_t access_flags;

	uint16_t this_class;
	uint16_t super_class;
	
	uint16_t interfaces_count;
	uint16_t *interfaces;

	uint16_t fields_count;
	java_field **fields;

	uint16_t methods_count;
	java_method **methods;

	bool synthetic;

	uint16_t inner_classes_count;
	java_inner_class **inner_classes;
	
} java_class;

const java_class* load_class(FILE *input);

void java_class_free(const java_class *class);

# endif /*STEPPINRAZOR_JAVA_CLASS_H*/
