CC=gcc
CFLAGS=-c -g -Wall
LDFLAGS=-lc
ASM=yasm
ASMFLAGS=-f elf64 -g dwarf2

all: bytecode_reader

bytecode_reader: bytecode_reader.o jvm.o
	$(CC) $(LDFLAGS) $^ -o $@

jvm.o: jvm.asm
	$(ASM) $(ASMFLAGS) $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f jvm.o bytecode_reader.o
	rm -f bytecode_reader
