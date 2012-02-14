# ifndef STEPPINRAZOR_JAVA_RUNTIME_CONSTANT_POOL_H
# define STEPPINRAZOR_JAVA_RUNTIME_CONSTANT_POOL_H

# include <stdint.h>
# include <stdbool.h>

# include "java_constant_pool.h"

typedef struct java_runtime_constant_pool_entry_classmember
{
	uint8_t *class;
	uint8_t *name;
	uint8_t *descriptor;

} java_runtime_constant_pool_entry_classmember;

typedef union java_runtime_constant_pool_entry
{
	uint32_t int_value;
	uint64_t long_value;
	float float_value;
	double double_value;

	uint8_t *string;
	
	java_runtime_constant_pool_entry_classmember *classmember;

} java_runtime_constant_pool_entry;

bool java_runtime_constant_pool_construct(uint16_t entry_count, java_constant_pool_entry **cp, java_runtime_constant_pool_entry ***runtime_cp, uint8_t **runtime_cp_types);
void java_runtime_constant_pool_free(uint16_t entry_count, java_runtime_constant_pool_entry **runtime_cp, uint8_t *runtime_cp_types);

# endif /*STEPPINRAZOR_JAVA_RUNTIME_CONSTANT_POOL_H*/
