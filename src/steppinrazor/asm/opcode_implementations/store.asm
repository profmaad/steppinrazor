%ifndef STEPPINRAZOR_OPCODE_IMPL_STORE_H
%define STEPPINRAZOR_OPCODE_IMPL_STORE_H

.store:
	mov al, [r10]
	pop rbx
	mov [r11+rax*8h], rbx
	add r10, 1h
	jmp run_method.loop
.wstore:
	mov al, [r10]
	pop rbx
	pop rbx
	mov [r11+rax*8h], rbx
	add r10, 1h
	jmp run_method.loop
	
.store_0:
	pop rax
	mov [r11], eax
	jmp run_method.loop
.store_1:
	pop rax
	mov [r11+8h], eax
	jmp run_method.loop
.store_2:
	pop rax
	mov [r11+10h], eax
	jmp run_method.loop
.store_3:
	pop rax
	mov [r11+18h], eax
	jmp run_method.loop

.wstore_0:
	pop rax
	pop rax
	mov [r11], rax
	jmp run_method.loop
.wstore_1:
	pop rax
	pop rax
	mov [r11+8h], rax
	jmp run_method.loop
.wstore_2:
	pop rax
	pop rax
	mov [r11+10h], rax
	jmp run_method.loop
.wstore_3:
	pop rax
	pop rax
	mov [r11+18h], rax
	jmp run_method.loop

%endif
