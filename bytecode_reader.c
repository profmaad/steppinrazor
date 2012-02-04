# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <stdint.h>
# include <stdlib.h>

# include <arpa/inet.h>

extern int run_method(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode);
//extern float run_method(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode);
//extern double run_method(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode);

typedef struct java_method_
{
	uint16_t max_stack;
	uint16_t max_locals;
	
	uint32_t bytecode_length;
	uint8_t *bytecode;
} java_method;

java_method* read_java_method(FILE *io)
{
	long bytecode_length = -1;

	if(fseek(io, 0L, SEEK_END) != 0) { printf("seek\n"); return NULL; }
	bytecode_length = ftell(io)-4L;
	rewind(io);

	java_method *method = (java_method*)malloc(sizeof(java_method));
	if(!method) { printf("malloc_0\n"); return NULL; }

	if(fread(&(method->max_stack), sizeof(method->max_stack), 1, io) != 1) { printf("fread(max_stack)\n"); return NULL; }
	if(fread(&(method->max_locals), sizeof(method->max_locals), 1, io) != 1) { printf("fread(max_locals)\n"); return NULL; }

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
	printf("bytecode length: %u\n", method->bytecode_length);

	int i;
	for(i = 0; i < method->bytecode_length; i++)
	{
		printf("%02hhx ", method->bytecode[i]);
		if((i+1) % 8 == 0) { printf("\n"); }
	}
	printf("\n");

//	printf("result: %f\n", run_method(method->max_stack, method->max_locals, method->bytecode));
	printf("result: %ld\n", run_method(method->max_stack, method->max_locals, method->bytecode));

	free(method->bytecode);
	free(method);

	if(fclose(input) != 0)
	{
		fprintf(stderr, "Failed to close input file: %s\n", strerror(errno));
		return 1;
	}

	return 0;
}
