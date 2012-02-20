# include <stdlib.h>
# include <string.h>

# include "java_runtime_method.h"

bool java_runtime_method_construct(java_runtime_method *rt_method, java_method *method)
{
	rt_method->max_stack = method->code->max_stack;
	rt_method->max_locals = method->code->max_locals;
	
	rt_method->code_length = method->code->code_length;
	rt_method->bytecode = (uint8_t*)malloc(rt_method->code_length+1);
	if(!rt_method->bytecode) { return false; }
	if(!memmove(rt_method->bytecode, method->code->bytecode, rt_method->code_length+1)) { return false; }

	rt_method->exception_handlers_count = method->code->exception_handlers_count;
	rt_method->exception_handlers = (java_exception_handler*)malloc(sizeof(java_exception_handler)*rt_method->exception_handlers_count);
	if(!rt_method->exception_handlers) { return false; }
	uint16_t i;
	for(i = 0; i < rt_method->exception_handlers_count; i++)
	{
		rt_method->exception_handlers[i].start_pc = method->code->exception_handlers[i]->start_pc;
		rt_method->exception_handlers[i].end_pc = method->code->exception_handlers[i]->end_pc;
		rt_method->exception_handlers[i].handler_pc = method->code->exception_handlers[i]->handler_pc;
		rt_method->exception_handlers[i].catch_type = method->code->exception_handlers[i]->catch_type;
	}

	return true;
}

void java_runtime_method_free(java_runtime_method *method)
{
	free(method->bytecode);
	free(method->exception_handlers);
}
