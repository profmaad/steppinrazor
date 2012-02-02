all: bytecode_reader

bytecode_reader: bytecode_reader.o jvm.o
	gcc -lc bytecode_reader.o jvm.o -o bytecode_reader

bytecode_reader.o: bytecode_reader.c
	gcc -c -g bytecode_reader.c -o bytecode_reader.o

jvm.o: jvm.asm
	yasm -f elf64 -g dwarf2 jvm.asm -o jvm.o

clean:
	rm -f jvm.o bytecode_reader.o
	rm -f bytecode_reader
