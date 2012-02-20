%ifndef STEPPINRAZOR_OPCODE_IMPL_LDC_H
%define STEPPINRAZOR_OPCODE_IMPL_LDC_H

.ldc:
	mov al, [r10]
	mov eax, DWORD [r12+rax*8h]
	cdqe
	push rax
	add r10, 1h
	jmp run_method.loop

.ldc_w:
	mov ax, [r10]
	xchg al, ah
	movzx rax, ax
	mov eax, DWORD [r12+rax*8h]
	cdqe
	push rax
	add r10, 2h
	jmp run_method.loop
	
.ldc2_w:
	mov ax, [r10]
	xchg al, ah
	movzx rax, ax
	mov rax, QWORD [r12+rax*8h]
	push rax
	push 0h
	add r10, 2h
	jmp run_method.loop

%endif
