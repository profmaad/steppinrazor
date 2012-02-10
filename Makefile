CC=clang
CFLAGS=-c -g -Wall
LDFLAGS=-lc
ASM=yasm
ASMFLAGS=-f elf64 -g dwarf2

all: bytecode_reader load_classfile

bytecode_reader: bytecode_reader.o jvm.o
	$(CC) $(LDFLAGS) $^ -o $@

load_classfile: load_classfile.o java_class.o java_constant_pool.o binary_helpers.o
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.asm
	$(ASM) $(ASMFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f *.o
	rm -f bytecode_reader load_classfile
