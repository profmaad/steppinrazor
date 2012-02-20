# ifndef STEPPINRAZOR_JAVA_METHOD_H
# define STEPPINRAZOR_JAVA_METHOD_H

# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>

struct java_constant_pool_entry;

typedef struct java_exception_handler
{
	uint16_t start_pc;
	uint16_t end_pc;
	uint16_t handler_pc;
	uint16_t catch_type;

} java_exception_handler;

typedef struct java_code
{
	uint16_t max_stack;
	uint16_t max_locals;

	uint32_t code_length;
	uint8_t *bytecode;

	uint16_t exception_handlers_count;
	java_exception_handler **exception_handlers;

} java_code;

typedef struct java_method
{
	uint16_t access_flags;
	
	uint16_t name_index;
	uint16_t descriptor_index;

	uint16_t attributes_count;

	java_code *code;
	
	uint16_t exceptions_count;
	uint16_t *exceptions;

	bool synthetic;

} java_method;

bool java_methods_parse(FILE *input, uint16_t *methods_count, java_method ***methods, struct java_constant_pool_entry **cp);
void java_methods_free(uint16_t methods_count, java_method **methods);

# endif /*STEPPINRAZOR_JAVA_METHOD_H*/
