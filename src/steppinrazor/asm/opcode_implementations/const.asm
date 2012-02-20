%ifndef STEPPINRAZOR_OPCODE_IMPL_CONST_H
%define STEPPINRAZOR_OPCODE_IMPL_CONST_H

.aconst_null:
	push 0x0
	jmp run_method.loop
	
.iconst_m1:
	push -1h
	jmp run_method.loop
.iconst_0:
	push 0h
	jmp run_method.loop
.iconst_1:
	push 1h
	jmp run_method.loop
.iconst_2:
	push 2h
	jmp run_method.loop
.iconst_3:
	push 3h
	jmp run_method.loop
.iconst_4:
	push 4h
	jmp run_method.loop
.iconst_5:
	push 5h
	jmp run_method.loop

.lconst_0:
	push 0h
	push 0h
	jmp run_method.loop
.lconst_1:
	push 1h
	push 0h
	jmp run_method.loop
	
.fconst_0:
	mov rax, [constants.float_0]
	push rax
	jmp run_method.loop
.fconst_1:
	mov rax, [constants.float_1]
	push rax
	jmp run_method.loop
.fconst_2:
	mov rax, [constants.float_2]
	push rax
	jmp run_method.loop
.dconst_0:
	mov rax, [constants.double_0]
	push rax
	push 0h
	jmp run_method.loop
.dconst_1:
	mov rax, [constants.double_1]
	push rax
	push 0h
	jmp run_method.loop
	
.bipush:
	mov al, [r10]
	movsx rax, al
	push rax
	add r10, 1h
	jmp run_method.loop
.sipush:
	mov ax, [r10]
	xchg al, ah
	movsx rax, ax
	push rax
	add r10, 2h
	jmp run_method.loop

%endif
