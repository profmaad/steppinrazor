# ifndef STEPPINRAZOR_JAVA_RUNTIME_FIELD_H
# define STEPPINRAZOR_JAVA_RUNTIME_FIELD_H

# include <stdint.h>
# include <stdbool.h>

# include <steppinrazor/parser/java_field.h>

struct java_runtime_object;

typedef union java_runtime_field
{
	struct java_runtime_object *reference_value;
	int32_t int_value;
	int64_t long_value;
	float float_value;
	double double_value;
} java_runtime_field;

bool java_runtime_field_construct(java_runtime_field *rt_field, java_field *field);

# endif /*STEPPINRAZOR_JAVA_RUNTIME_FIELD_H*/
