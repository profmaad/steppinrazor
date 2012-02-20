# Steppin' Razor - a JVM in assembler (mostly)

Rule one of Steppin' Razor: don't ask why. ;-)

## What already works

Multiple components already work:

* Java .class file parser
* running bytecode
* most opcodes (see below)
* returning results from methods
* retrieving primitive types from the constant pool (ldc*)

A lot of things are still missing:

* all opcodes relating to objects and array (new, newarray, ...)
* all opcodes relating to fields (getfield, putfield, ...)
* all opcodes relating to invoking methods (invokevirtual, invokestatic, ...)
* basically, there is just no support for objects yet, only operations on primitive data types work

Certain thinks are not in and probably won't ever be:

* .class file verification
* bytecode verification

I don't really see the use in bytecode verification. The compiler does it already and if needs be, you could just run a verifier beforehand and have it store the result with the hash of the .class file or something along those lines.

The assembly is written for x86_64 using NASM syntax. It will not work on x86 (wrong register names, first of all).

## What you need

* x86_64 POSIX-compatible system
* MMX, SSE, SSE2
* c compiler (gcc and clang are "tested")
* NASM assembler (or compatible, using yasm myself)
* SCons (for building)
* make (if you want to run tests)
* java jre (if you want to run the tests)
