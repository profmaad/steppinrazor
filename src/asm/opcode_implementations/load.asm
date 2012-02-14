%ifndef STEPPINRAZOR_OPCODE_IMPL_LOAD_H
%define STEPPINRAZOR_OPCODE_IMPL_LOAD_H

.load:
	mov al, [r10]
	mov rax, [r11+rax*8h]
	push rax
	add r10, 1h
	jmp run_method.loop
.wload:
	mov al, [r10]
	mov rax, [r11+rax*8h]
	push rax
	push 0h
	add r10, 1h
	jmp run_method.loop
	
.load_0:
	mov eax, [r11]
	push rax
	jmp run_method.loop
.load_1:
	mov eax, [r11+8h]
	push rax
	jmp run_method.loop
.load_2:
	mov eax, [r11+10h]
	push rax
	jmp run_method.loop
.load_3:
	mov eax, [r11+18h]
	push rax
	jmp run_method.loop

.wload_0:
	mov rax, [r11]
	push rax
	push 0h
	jmp run_method.loop
.wload_1:
	mov rax, [r11+8h]
	push rax
	push 0h
	jmp run_method.loop
.wload_2:
	mov rax, [r11+10h]
	push rax
	push 0h
	jmp run_method.loop
.wload_3:
	mov rax, [r11+18h]
	push rax
	push 0h
	jmp run_method.loop

%endif
