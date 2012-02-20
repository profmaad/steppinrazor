# ifndef STEPPINRAZOR_JAVA_RUNTIME_METHOD_H
# define STEPPINRAZOR_JAVA_RUNTIME_METHOD_H

# include <stdint.h>
# include <stdbool.h>

# include "java_method.h"

typedef struct java_runtime_method
{
	uint16_t max_stack;
	uint16_t max_locals;

	uint32_t code_length;
	uint8_t *bytecode;

	uint16_t exception_handlers_count;
	java_exception_handler *exception_handlers;

} java_runtime_method;

bool java_runtime_method_construct(java_runtime_method *rt_method, java_method *method);
void java_runtime_method_free(java_runtime_method *method);

# endif /*STEPPINRAZOR_JAVA_RUNTIME_METHOD_H*/
