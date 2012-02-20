# include <string.h>
# include <stdlib.h>

# include "java_runtime_constant_pool.h"

bool java_runtime_constant_pool_entry_classmember_parse(java_constant_pool_entry **cp, uint16_t index, java_runtime_constant_pool_entry *runtime_entry)
{
	java_constant_pool_entry *entry = cp[index];
	
	if(!(
		   cp[cp[entry->classmember_raw->class_index]->classref->index]->utf8 &&
		   cp[cp[entry->classmember_raw->name_and_type_index]->nameandtype->name_index]->utf8 &&
		   cp[cp[entry->classmember_raw->name_and_type_index]->nameandtype->descriptor_index]->utf8
		   ))
	{ return false; }
	
	runtime_entry->classmember = (java_runtime_constant_pool_entry_classmember*)malloc(sizeof(java_runtime_constant_pool_entry_classmember));
	if(!runtime_entry->classmember) { return false; }

	runtime_entry->classmember->class = (uint8_t*)strndup((const char*)cp[cp[entry->classmember_raw->class_index]->classref->index]->utf8->bytes, cp[cp[entry->classmember_raw->class_index]->classref->index]->utf8->length);
	if(!runtime_entry->classmember->class) { return false; }

	runtime_entry->classmember->name = (uint8_t*)strndup((const char*)cp[cp[entry->classmember_raw->name_and_type_index]->nameandtype->name_index]->utf8->bytes, cp[cp[entry->classmember_raw->name_and_type_index]->nameandtype->name_index]->utf8->length);
	if(!runtime_entry->classmember->name) { return false; }

	runtime_entry->classmember->descriptor = (uint8_t*)strndup((const char*)cp[cp[entry->classmember_raw->name_and_type_index]->nameandtype->descriptor_index]->utf8->bytes, cp[cp[entry->classmember_raw->name_and_type_index]->nameandtype->descriptor_index]->utf8->length);
	if(!runtime_entry->classmember->descriptor) { return false; }

	return true;
}

bool java_runtime_constant_pool_entry_construct(java_constant_pool_entry **cp, uint16_t index, java_runtime_constant_pool_entry *runtime_entry)
{
	java_constant_pool_entry *entry = cp[index];
	if(!entry) { return false; }

	switch(entry->tag)
	{
	case JAVA_CP_ENTRY_STRING:
	case JAVA_CP_ENTRY_CLASS:
		if(cp[entry->index_raw->index]->utf8)
		{
			runtime_entry->string = (uint8_t*)strndup((const char*)cp[entry->index_raw->index]->utf8->bytes, cp[entry->index_raw->index]->utf8->length);
			if(!runtime_entry->string) { return false; }
		}
		break;

	case JAVA_CP_ENTRY_INTEGER:
		if(entry->const_integer) { runtime_entry->int_value = entry->const_integer->value; }
		break;
	case JAVA_CP_ENTRY_FLOAT:
		if(entry->const_long) { runtime_entry->long_value = entry->const_long->value; }
		break;
	case JAVA_CP_ENTRY_LONG:
		if(entry->const_float) { runtime_entry->float_value = entry->const_float->value; }
		break;
	case JAVA_CP_ENTRY_DOUBLE:
		if(entry->const_double) { runtime_entry->double_value = entry->const_double->value; }
		break;

	case JAVA_CP_ENTRY_FIELDREF:
	case JAVA_CP_ENTRY_METHODREF:
	case JAVA_CP_ENTRY_INTERFACEMETHODREF:
		return java_runtime_constant_pool_entry_classmember_parse(cp, index, runtime_entry);
		break;
	default:
		return false;
	}

	return true;	
}
void java_runtime_constant_pool_entry_free(java_runtime_constant_pool_entry *entry, uint8_t type)
{
	switch(type)
	{
	case JAVA_CP_ENTRY_STRING:
	case JAVA_CP_ENTRY_CLASS:
		return free(entry->string);
		break;

	case JAVA_CP_ENTRY_FIELDREF:
	case JAVA_CP_ENTRY_METHODREF:
	case JAVA_CP_ENTRY_INTERFACEMETHODREF:
		if(entry->classmember)
		{
			free(entry->classmember->class);
			free(entry->classmember->name);
			free(entry->classmember->descriptor);
		}
		free(entry->classmember);
		break;
	}
}

bool java_runtime_constant_pool_construct(uint16_t entry_count, java_runtime_constant_pool_entry *runtime_cp, uint8_t *runtime_cp_types, java_constant_pool_entry **cp, java_runtime_class *rt_class)
{
	uint16_t i;
	for(i = 1; i < entry_count; i++)
	{
		switch(cp[i]->tag)
		{
		case JAVA_CP_ENTRY_STRING:
		case JAVA_CP_ENTRY_CLASS:
		case JAVA_CP_ENTRY_INTEGER:
		case JAVA_CP_ENTRY_FLOAT:
		case JAVA_CP_ENTRY_LONG:
		case JAVA_CP_ENTRY_DOUBLE:
		case JAVA_CP_ENTRY_FIELDREF:
		case JAVA_CP_ENTRY_METHODREF:
		case JAVA_CP_ENTRY_INTERFACEMETHODREF:		
			break;
		default:
			runtime_cp_types[i] = 0x0;
			continue;
		}

		if(!java_runtime_constant_pool_entry_construct(cp, i, &(runtime_cp[i]))) { return false; }
		runtime_cp_types[i] = cp[i]->tag;

		if(cp[i] && (cp[i]->tag == JAVA_CP_ENTRY_LONG || cp[i]->tag == JAVA_CP_ENTRY_DOUBLE)) { i++; }
	}

	return true;
}
void java_runtime_constant_pool_free(uint16_t entry_count, java_runtime_constant_pool_entry *runtime_cp, uint8_t *runtime_cp_types)
{
	int i;
	for(i = 0; i < entry_count; i++)
	{
		java_runtime_constant_pool_entry_free(&(runtime_cp[i]), runtime_cp_types[i]);
	}
}
