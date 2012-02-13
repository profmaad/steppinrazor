# include <stdlib.h>

# include "binary_helpers.h"
# include "java_attribute.h"
# include "java_constant_pool.h"
# include "java_method.h"

bool java_method_parse(FILE *input, java_method *method, java_constant_pool_entry **cp)
{
	if(!(
		   fread_uint16(input, &(method->access_flags)) &&
		   fread_uint16(input, &(method->name_index)) &&
		   fread_uint16(input, &(method->descriptor_index)) &&
		   fread_uint16(input, &(method->attributes_count))
		   ))
	{ return false; }

	long code_attr_pos = -1;
	long exceptions_attr_pos = -1;
	long attributes_end = -1;

	attributes_end = java_attribute_findmultiple(input, method->attributes_count, cp, "Code", &code_attr_pos, "Exceptions", &exceptions_attr_pos, NULL);
	if(attributes_end < 0)
	{
		return false;
	}

	printf("%ld, %ld\n", code_attr_pos, exceptions_attr_pos);

	return true;
}

bool java_methods_parse(FILE *input, uint16_t *methods_count, java_method ***methods, java_constant_pool_entry **cp)
{
	if(!fread_uint16(input, methods_count)) { return false; }

	*methods = (java_method**)malloc(sizeof(java_method*) * *methods_count);
	if(!*methods) { return false; }
  
	int i;
	for(i = 0; i < *methods_count; i++)
	{
		java_method *method = (java_method*)malloc(sizeof(java_method));
		if(!method) { return false; }

		if(!java_method_parse(input, method, cp)) { return false; }

		(*methods)[i] = method;
	}

	return true;	
}
void java_methods_free(uint16_t methods_count, java_method **methods)
{
	int i;
	for(i = 0; i < methods_count; i++)
	{
		if(methods[i]) { free(methods[i]); }
	}
}
