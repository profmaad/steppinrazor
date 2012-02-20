# include <stdio.h>
# include <stdlib.h>

# include <steppinrazor/common/binary_helpers.h>
# include <steppinrazor/parser/java_constant_pool.h>

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
}

bool java_constant_pool_entry_index_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->index_raw = (struct java_constant_pool_entry_index*)malloc(sizeof(struct java_constant_pool_entry_index));
	if(!entry->index_raw) { return false; }

	if(!fread_uint16(input, &(entry->string->index))) { return false; }

	return true;
}

bool java_constant_pool_entry_integer_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->const_integer = (java_constant_pool_entry_integer*)malloc(sizeof(java_constant_pool_entry_integer));
	if(!entry->const_integer) { return false; }

	if(!fread_uint32(input, &(entry->const_integer->value))) { return false; }

	return true;
}

bool java_constant_pool_entry_float_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->const_float = (java_constant_pool_entry_float*)malloc(sizeof(java_constant_pool_entry_float));
	if(!entry->const_float) { return false; }

	if(!fread_float(input, &(entry->const_float->value))) { return false; }

	return true;
}

bool java_constant_pool_entry_long_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->const_long = (java_constant_pool_entry_long*)malloc(sizeof(java_constant_pool_entry_long));
	if(!entry->const_long) { return false; }

	if(!fread_uint64(input, &(entry->const_long->value))) { return false; }

	return true;
}

bool java_constant_pool_entry_double_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->const_double = (java_constant_pool_entry_double*)malloc(sizeof(java_constant_pool_entry_double));
	if(!entry->const_double) { return false; }

	if(!fread_double(input, &(entry->const_double->value))) { return false; }

	return true;
}

bool java_constant_pool_entry_classmember_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->classmember_raw = (struct java_constant_pool_entry_classmember*)malloc(sizeof(struct java_constant_pool_entry_classmember));
	if(!entry->classmember_raw) { return false; }

	return
		fread_uint16(input, &(entry->classmember_raw->class_index)) &&
		fread_uint16(input, &(entry->classmember_raw->name_and_type_index))
		;
}

bool java_constant_pool_entry_nameandtype_parse(FILE *input, java_constant_pool_entry *entry)
{
	entry->nameandtype = (java_constant_pool_entry_nameandtype*)malloc(sizeof(java_constant_pool_entry_nameandtype));
	if(!entry->nameandtype) { return false; }

	return
		fread_uint16(input, &(entry->nameandtype->name_index)) &&
		fread_uint16(input, &(entry->nameandtype->descriptor_index))
		;
}

bool java_constant_pool_entry_parse(FILE *input, java_constant_pool_entry *entry)
{
	if(!fread_uint8(input, &(entry->tag))) { return false; }

	switch(entry->tag)
	{
	case JAVA_CP_ENTRY_UTF8:
		return java_constant_pool_entry_utf8_parse(input, entry);
		break;
	case JAVA_CP_ENTRY_STRING:
	case JAVA_CP_ENTRY_CLASS:
		return java_constant_pool_entry_index_parse(input, entry);
		break;

	case JAVA_CP_ENTRY_INTEGER:
		return java_constant_pool_entry_integer_parse(input, entry);
		break;
	case JAVA_CP_ENTRY_FLOAT:
		return java_constant_pool_entry_float_parse(input, entry);
		break;
	case JAVA_CP_ENTRY_LONG:
		return java_constant_pool_entry_long_parse(input, entry);
		break;
	case JAVA_CP_ENTRY_DOUBLE:
		return java_constant_pool_entry_double_parse(input, entry);
		break;

	case JAVA_CP_ENTRY_FIELDREF:
	case JAVA_CP_ENTRY_METHODREF:
	case JAVA_CP_ENTRY_INTERFACEMETHODREF:
		return java_constant_pool_entry_classmember_parse(input, entry);
		break;

	case JAVA_CP_ENTRY_NAMEANDTYPE:
		return java_constant_pool_entry_nameandtype_parse(input, entry);
		break;
	}

	return false;
}
void java_constant_pool_entry_free(java_constant_pool_entry *entry)
{
	switch(entry->tag)
	{
	case JAVA_CP_ENTRY_UTF8:
		if(entry->utf8) { java_constant_pool_entry_utf8_free(entry->utf8); }
		free(entry->utf8);
		break;
	case JAVA_CP_ENTRY_STRING:
	case JAVA_CP_ENTRY_CLASS:
		free(entry->index_raw);
		break;

	case JAVA_CP_ENTRY_INTEGER:
		free(entry->const_integer);
		break;
	case JAVA_CP_ENTRY_FLOAT:
		free(entry->const_float);
		break;
	case JAVA_CP_ENTRY_LONG:
		free(entry->const_long);
		break;
	case JAVA_CP_ENTRY_DOUBLE:
		free(entry->const_double);
		break;

	case JAVA_CP_ENTRY_FIELDREF:
	case JAVA_CP_ENTRY_METHODREF:
	case JAVA_CP_ENTRY_INTERFACEMETHODREF:
		free(entry->classmember_raw);
		break;

	case JAVA_CP_ENTRY_NAMEANDTYPE:
		free(entry->nameandtype);
		break;
	}
}

bool java_constant_pool_parse(FILE *input, uint16_t *cp_count, java_constant_pool_entry ***cp)
{
	if(!fread_uint16(input, cp_count)) { return false; }

	*cp = (java_constant_pool_entry**)malloc(sizeof(java_constant_pool_entry*) * *cp_count);
	if(!*cp) { return false; }
  
	int i;
	for(i = 1; i < *cp_count; i++)
	{
		(*cp)[i] = (java_constant_pool_entry*)malloc(sizeof(java_constant_pool_entry));
		if(!(*cp)[i]) { return false; }

		if(!java_constant_pool_entry_parse(input, (*cp)[i])) { return false; }

		if( ((*cp)[i]->tag == JAVA_CP_ENTRY_DOUBLE) || ((*cp)[i]->tag == JAVA_CP_ENTRY_LONG) )
		{ i++; }
	}

	return true;
}
void java_constant_pool_free(uint16_t cp_count, java_constant_pool_entry **cp)
{
	int i;
	for(i = 1; i < cp_count; i++)
	{
		if(cp[i]) { java_constant_pool_entry_free(cp[i]); }
		free(cp[i]);
	}
}
