%ifndef STEPPINRAZOR_OPCODE_IMPL_TYPECONVERSION_H
%define STEPPINRAZOR_OPCODE_IMPL_TYPECONVERSION_H

.i2l:
	pop rax
	cdqe
	push rax
	push 0h
	jmp run_method.loop	
.i2f:
	cvtsi2ss xmm0, DWORD [rsp]
	movss [rsp], xmm0
	jmp run_method.loop	
.i2d:
	cvtsi2sd xmm0, DWORD [rsp]
	movsd [rsp], xmm0
	push 0h
	jmp run_method.loop	
.l2i:
	pop rax
	mov rax, QWORD [rsp]
	mov [rsp], eax
	jmp run_method.loop	
.l2f:
	pop rax
	cvtsi2ss xmm0, QWORD [rsp]
	movss [rsp], xmm0
	jmp run_method.loop	
.l2d:
	cvtsi2sd xmm0, QWORD [rsp+8h]
	movsd [rsp+8h], xmm0
	jmp run_method.loop	
.f2i:
	cvttss2si eax, DWORD [rsp]
	mov DWORD [rsp], eax
	jmp run_method.loop	
.f2l:
	cvttss2si rax, DWORD [rsp]
	mov QWORD [rsp], rax
	push 0h
	jmp run_method.loop	
.f2d:
	cvtss2sd xmm0, [rsp]
	movsd [rsp], xmm0
	push 0h
	jmp run_method.loop	
.d2i:
	pop rax
	cvttsd2si eax, QWORD [rsp]
	mov DWORD [rsp], eax
	jmp run_method.loop	
.d2l:
	cvttsd2si rax, QWORD [rsp+8h]
	mov QWORD [rsp+8h], rax
	jmp run_method.loop	
.d2f:
	pop rax
	cvtsd2ss xmm0, [rsp]
	movss [rsp], xmm0
	jmp run_method.loop	
.i2b:
	pop rax
	movsx rax, al
	push rax
	jmp run_method.loop	
.i2c:
	pop rax
	movzx rax, al
	push rax
	jmp run_method.loop	
.i2s:
	pop rax
	movsx rax, ax
	push rax
	jmp run_method.loop	

%endif
