%ifndef STEPPINRAZOR_OPCODE_IMPL_ARITHMETIC_H
%define STEPPINRAZOR_OPCODE_IMPL_ARITHMETIC_H
	
.iadd:
	pop rax
	pop rbx
	add eax, ebx
	push rax
	jmp run_method.loop
.ladd:
	mov rax, [rsp+8h]	
	add rax, [rsp+18h]
	mov [rsp+18h], rax
	add rsp, 10h
	jmp run_method.loop
.fadd:
	xorps xmm0, xmm0
	movss xmm0, [rsp]
	addss xmm0, [rsp+8h]
	movss [rsp+8h], xmm0
	add rsp, 8h
	jmp run_method.loop
.dadd:
	xorps xmm0, xmm0
	movlpd xmm0, [rsp+8h]
	addsd xmm0, [rsp+18h]
	movlpd [rsp+18h], xmm0
	add rsp, 10h
	jmp run_method.loop

.isub:
	pop rax
	pop rbx
	sub ebx, eax
	push rbx
	jmp run_method.loop
.lsub:
	mov rbx, [rsp+18h]
	sub rbx, [rsp+8h]
	mov [rsp+18h], rbx
	add rsp, 10h
	jmp run_method.loop
.fsub:
	xorps xmm0, xmm0
	movss xmm0, [rsp+8h]
	subss xmm0, [rsp]
	movss [rsp+8h], xmm0
	add rsp, 8h
	jmp run_method.loop
.dsub:
	xorps xmm0, xmm0
	movlpd xmm0, [rsp+18h]
	subsd xmm0, [rsp+8h]
	movlpd [rsp+18h], xmm0
	add rsp, 10h
	jmp run_method.loop

.imul:
	pop rax
	imul eax, [rsp]
	mov [rsp], rax
	jmp run_method.loop
.lmul:
	mov rax, [rsp+8h]
	imul rax, [rsp+18h]
	mov [rsp+18h], rax
	add rsp, 10h
	jmp run_method.loop
.fmul:
	xorps xmm0, xmm0
	movss xmm0, [rsp+8h]
	mulss xmm0, [rsp]
	movss [rsp+8h], xmm0
	add rsp, 8h
	jmp run_method.loop
.dmul:
	xorps xmm0, xmm0
	movlpd xmm0, [rsp+18h]
	mulsd xmm0, [rsp+8h]
	movlpd [rsp+18h], xmm0
	add rsp, 10h
	jmp run_method.loop

.idiv:
	pop rbx
	pop rax
	mov edx, eax
	shr edx, 0x1f
	idiv ebx
	push rax
	jmp run_method.loop
.ldiv:
	mov rax, [rsp+18h]
	mov rdx, rax
	shr rdx, 0x3f
	idiv QWORD [rsp+8h]
	mov [rsp+18h], rax
	add rsp, 10h
	jmp run_method.loop
.fdiv:
	xorps xmm0, xmm0
	movss xmm0, [rsp+8h]
	divss xmm0, [rsp]
	movss [rsp+8h], xmm0
	add rsp, 8h
	jmp run_method.loop
.ddiv:
	xorps xmm0, xmm0
	movlpd xmm0, [rsp+18h]
	divsd xmm0, [rsp+8h]
	movlpd [rsp+18h], xmm0
	add rsp, 10h
	jmp run_method.loop

.irem:
	pop rbx
	pop rax
	mov edx, eax
	sar edx, 0x1f
	idiv ebx
	push rdx
	jmp run_method.loop
.lrem:
	mov rax, [rsp+18h]
	mov rdx, rax
	sar rdx, 0x3f
	idiv QWORD [rsp+8h]
	mov [rsp+18h], rdx
	add rsp, 10h
	jmp run_method.loop
.frem:
	finit
	fld DWORD [rsp]
	fld DWORD [rsp+8h]
.frem_l:
	fprem
	fstsw ax
	fwait
	sahf
	jp .frem_l
	fstp DWORD [rsp+8h]
	add rsp, 8h
	jmp run_method.loop
.drem:
	finit
	fld QWORD [rsp+8]
	fld QWORD [rsp+18h]
.drem_l:
	fprem
	fstsw ax
	fwait
	sahf
	jp .drem_l
	fstp QWORD [rsp+18h]
	add rsp, 10h
	jmp run_method.loop

.ineg:
	neg DWORD [rsp]
	jmp run_method.loop
.lneg:
	neg QWORD [rsp+8h]
	jmp run_method.loop
.fneg:
	jmp run_method.loop
.dneg:
	jmp run_method.loop	

.iinc:
	mov bl, [r10]
	movzx rbx, bl
	mov al, [r10+1]
	movsx rax, al
	add [r11+rbx*8h], rax
	add r10, 2h
	jmp run_method.loop	

%endif
