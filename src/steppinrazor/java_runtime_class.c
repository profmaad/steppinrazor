# include <stdlib.h>
# include <string.h>

# include <steppinrazor/java_runtime_class.h>

bool java_runtime_class_construct(java_runtime_class *rt_class, const java_class *class)
{
	rt_class->constant_pool_count = class->constant_pool_count;
	rt_class->fields_count = class->fields_count;
	rt_class->methods_count = class->methods_count;
	
	// TODO: class registry?
	rt_class->super_class = NULL;

	rt_class->constant_pool = (java_runtime_constant_pool_entry*)malloc(sizeof(java_runtime_constant_pool_entry)*rt_class->constant_pool_count);
	if(!rt_class->constant_pool) { return false; }

	rt_class->constant_pool_types = (uint8_t*)malloc(rt_class->constant_pool_count);
	if(!rt_class->constant_pool_count) { return false; }

	rt_class->fields = (java_runtime_field*)malloc(sizeof(java_runtime_field)*rt_class->fields_count);
	if(!rt_class->fields) { return false; }

	rt_class->methods = (java_runtime_method*)malloc(sizeof(java_runtime_method)*rt_class->methods_count);
	if(!rt_class->methods) { return false; }

	uint16_t i;
	for(i = 0; i < rt_class->fields_count; i++)
	{
		if(!java_runtime_field_construct(&(rt_class->fields[i]), class->fields[i])) { return false; }
	}
	for(i = 0; i < rt_class->methods_count; i++)
	{
		if(!java_runtime_method_construct(&(rt_class->methods[i]), class->methods[i])) { return false; }

		if(class->constant_pool[class->methods[i]->name_index]->utf8->bytes)
		{
			if(class->constant_pool[class->methods[i]->name_index]->utf8->length == 6 && strncmp((const char*)class->constant_pool[class->methods[i]->name_index]->utf8->bytes, "<init>", 6) == 0)
			{ rt_class->init = &(rt_class->methods[i]); }
			
			else if(class->constant_pool[class->methods[i]->name_index]->utf8->length == 8 && strncmp((const char*)class->constant_pool[class->methods[i]->name_index]->utf8->bytes, "<clinit>", 8) == 0)
			{ rt_class->clinit = &(rt_class->methods[i]); }

		}
	}

	java_runtime_constant_pool_construct(rt_class->constant_pool_count, rt_class->constant_pool, rt_class->constant_pool_types, class->constant_pool, rt_class);

	return true;
}

void java_runtime_class_free(java_runtime_class *c)
{
	uint16_t i;

	if(c->constant_pool && c->constant_pool_types) { java_runtime_constant_pool_free(c->constant_pool_count, c->constant_pool, c->constant_pool_types); }
	free(c->constant_pool);
	free(c->constant_pool_types);
	
	free(c->fields);

	if(c->methods)
	{
		for(i = 0; i < c->methods_count; i++)
		{
			java_runtime_method_free(&(c->methods[i]));
		}
	}
	free(c->methods);

	java_runtime_method_free(c->clinit);
	java_runtime_method_free(c->init);
}
