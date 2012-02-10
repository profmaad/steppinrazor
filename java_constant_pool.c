# include <stdio.h>
# include <stdlib.h>

# include "binary_helpers.h"
# include "java_constant_pool.h"

bool java_constant_pool_entry_utf8_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->utf8 = (java_constant_pool_entry_utf8*)malloc(sizeof(java_constant_pool_entry_utf8));
	if(!entry->utf8) { return false; }

	if(!fread_uint16(input, &(entry->utf8->length))) { return false; }

	entry->utf8->bytes = (uint8_t*)malloc(entry->utf8->length);
	if(!entry->utf8->bytes) { return false; }

	if(fread(entry->utf8->bytes, 1, entry->utf8->length, input) != entry->utf8->length) { return false; }

	return true;
}
void java_constant_pool_entry_utf8_free(java_constant_pool_entry_utf8 *entry)
{
	free(entry->bytes);
	free(entry);
}

bool java_constant_pool_entry_string_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->string = (java_constant_pool_entry_string*)malloc(sizeof(java_constant_pool_entry_string));
	if(!entry->string) { return false; }

	if(!fread_uint16(input, &(entry->string->index))) { return false; }

	return true;
}
void java_constant_pool_entry_string_free(java_constant_pool_entry_string *entry)
{
	free(entry);
}

bool java_constant_pool_parse(FILE *input, uint16_t num_entries, java_constant_pool_entry **cp)
{
	int i;
	uint8_t tag;
	for(i = 1; i < num_entries; i++)
	{
		if(!fread_uint8(input, &tag)) { return false; }

		java_constant_pool_entry *entry = (java_constant_pool_entry*)malloc(sizeof(java_constant_pool_entry));
		if(!entry) { return false; }

		entry->tag = tag;

		switch(tag)
		{
		case JAVA_CP_ENTRY_UTF8:
			if(!java_constant_pool_entry_utf8_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_STRING:
			if(!java_constant_pool_entry_string_parse(input, entry)) { return false; }
			break;

		case JAVA_CP_ENTRY_INTEGER:
			if(!java_constant_pool_entry_integer_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_FLOAT:
			if(!java_constant_pool_entry_float_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_LONG:
			if(!java_constant_pool_entry_long_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_DOUBLE:
			if(!java_constant_pool_entry_double_parse(input, entry)) { return false; }
			break;

		case JAVA_CP_ENTRY_CLASS:
			if(!java_constant_pool_entry_class_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_FIELDREF:
			if(!java_constant_pool_entry_fieldref_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_METHODREF:
			if(!java_constant_pool_entry_methodref_parse(input, entry)) { return false; }
			break;
		case JAVA_CP_ENTRY_INTERFACEMETHODREF:
			if(!java_constant_pool_entry_interfacemethodref_parse(input, entry)) { return false; }
			break;

		case JAVA_CP_ENTRY_NAMEANDTYPE:
			if(!java_constant_pool_entry_nameandtype_parse(input, entry)) { return false; }
			break;
		}
	}

	return true;
}
