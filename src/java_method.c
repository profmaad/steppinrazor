# include <stdlib.h>
# include <string.h>
# include <errno.h>

# include "binary_helpers.h"
# include "java_attribute.h"
# include "java_constant_pool.h"
# include "java_method.h"

bool java_method_code_exception_handler_parse(FILE *input, java_exception_handler *handler)
{
	if(!(
		   fread_uint16(input, &(handler->start_pc)) && 						      
		   fread_uint16(input, &(handler->end_pc)) && 						      
		   fread_uint16(input, &(handler->handler_pc)) && 						      
		   fread_uint16(input, &(handler->catch_type))
		   ))
	{ return false; }

	return true;
}

bool java_method_code_parse(FILE *input, java_code *code)
{
	if(!(
		   fread_uint16(input, &(code->max_stack)) &&
		   fread_uint16(input, &(code->max_locals)) &&
		   fread_uint32(input, &(code->code_length))
		   ))
	{ return false; }

	code->bytecode = (uint8_t*)malloc(code->code_length+1);
	if(!code->bytecode) { return false; }

	if(fread(code->bytecode, 1, code->code_length, input) != code->code_length) { return false; }
	code->bytecode[code->code_length] = 0xff;

	if(!fread_uint16(input, &(code->exception_handlers_count))) { return false; }

	code->exception_handlers = (java_exception_handler**)malloc(sizeof(java_exception_handler*)*code->exception_handlers_count);
	if(!code->exception_handlers) { return false; }

	int i;
	for(i = 0; i < code->exception_handlers_count; i++)
	{
		code->exception_handlers[i] = (java_exception_handler*)malloc(sizeof(java_exception_handler));
		if(!code->exception_handlers[i]) { return false; }

		if(!java_method_code_exception_handler_parse(input, code->exception_handlers[i])) { return false;}
	}

	return true;
}
void java_method_code_free(java_code *code)
{
	free(code->bytecode);

	if(code->exception_handlers)
	{
		int i;
		for(i = 0; i < code->exception_handlers_count; i++)
		{
			free(code->exception_handlers[i]);
		}
	}

	free(code->exception_handlers);
}

bool java_method_parse(FILE *input, java_method *method, java_constant_pool_entry **cp)
{
	method->synthetic = false;

	if(!(
		   fread_uint16(input, &(method->access_flags)) &&
		   fread_uint16(input, &(method->name_index)) &&
		   fread_uint16(input, &(method->descriptor_index)) &&
		   fread_uint16(input, &(method->attributes_count))
		   ))
	{ return false; }

	long code_attr_pos = -1;
	long exceptions_attr_pos = -1;
	long synthetic_attr_pos = -1;
	long attributes_end = -1;

	attributes_end = java_attribute_findmultiple(input, method->attributes_count, cp, "Code", &code_attr_pos, "Exceptions", &exceptions_attr_pos, "Synthetic", &synthetic_attr_pos, NULL);
	if(attributes_end < 0) { return false; }

	if(code_attr_pos >= 0 && (fseek(input, code_attr_pos+4, SEEK_SET) == 0))
	{
		java_code *code = (java_code*)malloc(sizeof(java_code));
		if(!code) { return false; }

		if(!java_method_code_parse(input, code)) { return false; }

		method->code = code;
	}

	if(exceptions_attr_pos >= 0)
	{
		if(!(fseek(input, exceptions_attr_pos+4, SEEK_SET) == 0)) { return false; }
		if(!fread_uint16(input, &(method->exceptions_count))) { return false; }
		method->exceptions = (uint16_t*)malloc(sizeof(uint16_t) * method->exceptions_count);
		if(!method->exceptions) { return false; }

		int i;
		for(i = 0; i < method->exceptions_count; i++)
		{
			if(!fread_uint16(input, &(method->exceptions[i]))) { return false; }
		}
	}

	if(synthetic_attr_pos >= 0) { method->synthetic = true; }

	fseek(input, attributes_end, SEEK_SET);

	return true;
}
void java_method_free(java_method *method)
{
	if(method->code) { java_method_code_free(method->code); }
	free(method->code);

	free(method->exceptions);
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
		if(methods[i]) { java_method_free(methods[i]); }
		free(methods[i]);
	}
}
