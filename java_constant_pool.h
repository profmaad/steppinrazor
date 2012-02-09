# ifndef STEPPINRAZOR_JAVA_CONSTANT_POOL_H
# define STEPPINRAZOR_JAVA_CONSTANT_POOL_H

# include <stdint.h>

enum java_constant_pool_entry_type
{
	JAVA_CP_ENTRY_UTF8 = 1,
	JAVA_CP_ENTRY_STRING = 8,

	JAVA_CP_ENTRY_INTEGER = 3,
	JAVA_CP_ENTRY_FLOAT = 4,
	JAVA_CP_ENTRY_LONG = 5,
	JAVA_CP_ENTRY_DOUBLE = 6,

	JAVA_CP_ENTRY_CLASS = 7,
	JAVA_CP_ENTRY_FIELDREF = 9,
	JAVA_CP_ENTRY_METHODREF = 10,
	JAVA_CP_ENTRY_INTERFACEMETHODREF = 11,

	JAVA_CP_ENTRY_NAMEANDTYPE = 12
};

typedef struct java_constant_pool_entry_utf8_
{
	uint16_t length;
	uint8_t *bytes;

} java_constant_pool_entry_utf8;
struct java_constant_pool_entry_index_
{
	uint16_t index;
};
typedef struct java_constant_pool_entry_index_ java_constant_pool_entry_string;
typedef struct java_constant_pool_entry_index_ java_constant_pool_entry_class;

typedef struct java_constant_pool_entry_integer_
{
	uint32_t value;
} java_constant_pool_entry_integer;
typedef struct java_constant_pool_entry_float_
{
	float value;
} java_constant_pool_entry_float;
typedef struct java_constant_pool_entry_long_
{
	uint64_t value;
} java_constant_pool_entry_long;
typedef struct java_constant_pool_entry_double_
{
	double value;
} java_constant_pool_entry_double;

struct java_constant_pool_entry_classmember_
{
	uint16_t class_index;
	uint16_t name_and_type_index;
};
typedef struct java_constant_pool_entry_classmember_ java_constant_pool_entry_fieldref;
typedef struct java_constant_pool_entry_classmember_ java_constant_pool_entry_methodref;
typedef struct java_constant_pool_entry_classmember_ java_constant_pool_entry_interfacemethodref;

typedef struct java_constant_pool_entry_nameandtype_
{
	uint16_t name_index;
	uint16_t descriptor_index;
} java_constant_pool_entry_nameandtype;

typedef struct java_constant_pool_entry_
{
	uint8_t tag;
	union
	{
		java_constant_pool_entry_utf8 utf8;
		java_constant_pool_entry_string string;

     		java_constant_pool_entry_integer const_integer;
     		java_constant_pool_entry_float const_float;
     		java_constant_pool_entry_long const_long;
     		java_constant_pool_entry_double const_double;

     		java_constant_pool_entry_class class;
     		java_constant_pool_entry_fieldref fieldref;
     		java_constant_pool_entry_methodref methodref;
     		java_constant_pool_entry_interfacemethodref interfacemethodref;

     		java_constant_pool_entry_nameandtype nameandtype;
	};
} java_constant_pool_entry;

# endif /*STEPPINRAZOR_JAVA_CONSTANT_POOL_H*/
