# ifndef STEPPINRAZOR_JVM_H
# define STEPPINRAZOR_JVM_H

typedef struct java_runtime_constant_pool java_runtime_constant_pool;

extern void* run_method(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode);
extern float run_method_float(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode);
extern double run_method_double(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode);

# endif /*STEPPINRAZOR_JVM_H*/
