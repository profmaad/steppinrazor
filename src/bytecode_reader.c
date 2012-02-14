# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <stdlib.h>

# include <arpa/inet.h>

# include "jvm.h"

typedef struct java_method_
{
	uint16_t max_stack;
	uint16_t max_locals;
	char return_type;
	
	uint32_t bytecode_length;
	uint8_t *bytecode;
} java_method;

java_method* read_java_method(FILE *io)
{
	long bytecode_length = -1;

	if(fseek(io, 0L, SEEK_END) != 0) { printf("seek\n"); return NULL; }
	bytecode_length = ftell(io)-5L;
	rewind(io);

	java_method *method = (java_method*)malloc(sizeof(java_method));
	if(!method) { printf("malloc_0\n"); return NULL; }

	if(fread(&(method->max_stack), sizeof(method->max_stack), 1, io) != 1) { printf("fread(max_stack)\n"); return NULL; }
	if(fread(&(method->max_locals), sizeof(method->max_locals), 1, io) != 1) { printf("fread(max_locals)\n"); return NULL; }
	if(fread(&(method->return_type), sizeof(method->return_type), 1, io) != 1) { printf("fread(return_type)\n"); return NULL; }

	method->max_stack = ntohs(method->max_stack);
	method->max_locals = ntohs(method->max_locals);
	
	method->bytecode = NULL;
	method->bytecode = (uint8_t*)malloc(bytecode_length+1);
	if(!(method->bytecode)) { printf("malloc_1\n"); return NULL; }

	if(fread(method->bytecode, 1, bytecode_length, io) != bytecode_length) { printf("fread(bytecode)\n"); return NULL; }
	method->bytecode_length = bytecode_length+1;
	method->bytecode[bytecode_length] = 0xff;

	return method;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		printf("Usage: %s <inputfile>\n", argv[0]);
		return 1;
	}

	const char *input_filename = argv[1];

	FILE *input = NULL;

	input = fopen(input_filename, "rb");
	if(!input)
	{
		fprintf(stderr, "Failed to open input file: %s\n", strerror(errno));
		return 1;
	}

	java_method *method = read_java_method(input);
	if(!method)
	{
		fprintf(stderr, "Failed to read method from file\n");
		return 2;
	}

	printf("max stack: %hu\n", method->max_stack);
	printf("max locals: %hu\n", method->max_locals);
	printf("return type: %c\n", method->return_type);
	printf("bytecode length: %u\n", method->bytecode_length);

	int i;
	for(i = 0; i < method->bytecode_length; i++)
	{
		printf("%02hhx ", method->bytecode[i]);
		if((i+1) % 8 == 0) { printf("\n"); }
	}
	printf("\n");

	

	switch(method->return_type)
	{
	case 'Z':
		printf("result: %hhu\n", (uint8_t)run_method(method->max_stack, method->max_locals, method->bytecode));
		break;
	case 'B':
		printf("result: %hhd\n", (int8_t)run_method(method->max_stack, method->max_locals, method->bytecode));
		break;
	case 'C':
		printf("result: %hhu\n", (uint8_t)run_method(method->max_stack, method->max_locals, method->bytecode));
		break;
	case 'S':
		printf("result: %hd\n", (int16_t)run_method(method->max_stack, method->max_locals, method->bytecode));
		break;
	case 'I':
		printf("result: %d\n", (int)run_method(method->max_stack, method->max_locals, method->bytecode));
		break;
	case 'J':
		printf("result: %ld\n", (long)run_method(method->max_stack, method->max_locals, method->bytecode));
		break;      
	case 'F':
		printf("result: %f\n", run_method_float(method->max_stack, method->max_locals, method->bytecode));
		break;      
	case 'D':
		printf("result: %f\n", run_method_double(method->max_stack, method->max_locals, method->bytecode));
		break;
	case 'L':
		printf("result: %p\n", run_method(method->max_stack, method->max_locals, method->bytecode));
	}

	free(method->bytecode);
	free(method);

	if(fclose(input) != 0)
	{
		fprintf(stderr, "Failed to close input file: %s\n", strerror(errno));
		return 1;
	}

	return 0;
}
