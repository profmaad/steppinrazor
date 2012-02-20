CC=clang
CFLAGS=-c -g -Wall
LDFLAGS=-lc
ASM=yasm
ASMFLAGS=-f elf64 -g dwarf2
OFFSET_GEN=../tools/offset_gen.rb
RUBY=ruby

OFFSET_HEADERS=java_class.h java_attribute.h java_constant_pool.h java_field.h java_method.h java_runtime_constant_pool.h

all: asm/offsets.asm load_classfile class_runner test_runner

load_classfile: load_classfile.o java_class.o java_constant_pool.o java_field.o java_method.o java_attribute.o binary_helpers.o java_runtime_constant_pool.o java_runtime_class.o java_runtime_field.o java_runtime_method.o
	$(CC) $(LDFLAGS) $^ -o $@

class_runner: class_runner.o java_class.o java_constant_pool.o java_field.o java_method.o java_attribute.o binary_helpers.o java_runtime_constant_pool.o java_runtime_class.o java_runtime_field.o java_runtime_method.o asm/jvm.o
	$(CC) $(LDFLAGS) $^ -o $@

test_runner: test_runner.o java_class.o java_constant_pool.o java_field.o java_method.o java_attribute.o binary_helpers.o java_runtime_constant_pool.o java_runtime_class.o java_runtime_field.o java_runtime_method.o asm/jvm.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o */*.o
	rm -f load_classfile class_runner test_runner
	rm -f offsets.c offsets asm/offsets.asm

asm/offsets.asm: offsets
	./offsets > $@

offsets: offsets.c
	$(CC) -x c -g -Wall $< -o $@

offsets.c: $(OFFSET_GEN)
	$(RUBY) $< $(OFFSET_HEADERS) > $@