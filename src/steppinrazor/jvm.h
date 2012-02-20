# ifndef STEPPINRAZOR_JVM_H
# define STEPPINRAZOR_JVM_H

union java_runtime_constant_pool_entry;

extern void* run_method(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode, union java_runtime_constant_pool_entry *runtime_cp);
extern float run_method_float(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode, union java_runtime_constant_pool_entry *runtime_cp);
extern double run_method_double(uint16_t max_stack, uint16_t max_locals, uint8_t* bytecode, union java_runtime_constant_pool_entry *runtime_cp);

# endif /*STEPPINRAZOR_JVM_H*/
