section .data

%include "opcode_table.asm"
%include "constants_data.asm"
	
section .text
	global run_method
	global run_method_float
	global run_method_double

run_method_float:
run_method_double:
run_method:
	push rbp
	mov rbp, rsp

	;; store bytecode pointer
	mov r10, rdx

	;; store bytecode start address (needed for tableswitch)
	push r10

	;; reserve space for local variables (4 bytes per slot)
	lea rax, [rsi*8h]
	sub rsp, rax
	;; and save a pointer to the first local variable
	mov r11, rsp

.loop:	xor rax, rax
	mov al, [r10]
	add r10, 1h
	jmp [rax*8+opcodes]

.end:	mov rsp, rbp
	pop rbp
	ret

opcode_impl:

%include "opcode_implementations/const.asm"
%include "opcode_implementations/load.asm"
%include "opcode_implementations/store.asm"
%include "opcode_implementations/stack.asm"
%include "opcode_implementations/arithmetic.asm"
%include "opcode_implementations/bitop.asm"
%include "opcode_implementations/comparison.asm"
%include "opcode_implementations/jump.asm"
%include "opcode_implementations/typeconversion.asm"
%include "opcode_implementations/method.asm"

