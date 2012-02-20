# ifndef STEPPINRAZOR_JAVA_RUNTIME_CLASS_H
# define STEPPINRAZOR_JAVA_RUNTIME_CLASS_H

# include <stdint.h>
# include <stdbool.h>

# include "java_class.h"

# include "java_runtime_constant_pool.h"
# include "java_runtime_field.h"
# include "java_runtime_method.h"

typedef struct java_runtime_class
{
	uint16_t constant_pool_count;
	union java_runtime_constant_pool_entry *constant_pool;
	uint8_t *constant_pool_types;

	struct java_runtime_class *super_class;

	uint16_t fields_count;
	java_runtime_field *fields;

	uint16_t methods_count;
	java_runtime_method *methods;

	java_runtime_method *clinit;
	java_runtime_method *init;
} java_runtime_class;

bool java_runtime_class_construct(java_runtime_class *rt_class, const java_class *class);
void java_runtime_class_free(java_runtime_class *c);

#endif /*STEPPINRAZOR_JAVA_RUNTIME_CLASS_H*/
