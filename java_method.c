# include <stdlib.h>

# include "binary_helpers.h"
# include "java_attribute.h"
# include "java_method.h"

bool java_method_parse(FILE *input, java_method *method)
{
	if(!(
		   fread_uint16(input, &(method->access_flags)) &&
		   fread_uint16(input, &(method->name_index)) &&
		   fread_uint16(input, &(method->descriptor_index)) &&
		   fread_uint16(input, &(method->attributes_count))
		   ))
	{ return false; }

	java_attribute_skipall(input, method->attributes_count);

	return true;
}

bool java_methods_parse(FILE *input, uint16_t *methods_count, java_method ***methods)
{
	if(!fread_uint16(input, methods_count)) { return false; }

	*methods = (java_method**)malloc(sizeof(java_method*) * *methods_count);
	if(!*methods) { return false; }
  
	int i;
	for(i = 0; i < *methods_count; i++)
	{
		java_method *method = (java_method*)malloc(sizeof(java_method));
		if(!method) { return false; }

		if(!java_method_parse(input, method)) { return false; }

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
