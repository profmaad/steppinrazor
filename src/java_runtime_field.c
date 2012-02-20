# include "java_runtime_field.h"

bool java_runtime_field_construct(java_runtime_field *rt_field, java_field *field)
{
	rt_field->long_value = field->long_value;

	return true;
}
