%ifndef STEPPINRAZOR_OPCODE_IMPL_BITOP_H
%define STEPPINRAZOR_OPCODE_IMPL_BITOP_H

.ishl:
	pop rcx
	sal DWORD [rsp], cl
	jmp run_method.loop
.lshl:
	pop rcx
	sal QWORD [rsp+8h], cl
	jmp run_method.loop
.ishr:
	pop rcx
	sar DWORD [rsp], cl
	jmp run_method.loop	
.lshr:
	pop rcx
	sar QWORD [rsp+8h], cl
	jmp run_method.loop	
.iushr:
	pop rcx
	shr DWORD [rsp], cl
	jmp run_method.loop	
.lushr:
	pop rcx
	shr QWORD [rsp+8h], cl
	jmp run_method.loop	

.iand:
	pop rax
	and [rsp+8h], eax
	add rsp, 8h
	jmp run_method.loop	
.land:
	mov rax, [rsp+8h]
	and [rsp+18h], rax
	add rsp, 10h
	jmp run_method.loop	
.ior:
	pop rax
	or [rsp+8h], eax
	add rsp, 8h
	jmp run_method.loop	
.lor:
	mov rax, [rsp+8h]
	or [rsp+18h], rax
	add rsp, 10h
	jmp run_method.loop	
.ixor:
	pop rax
	xor [rsp+8h], eax
	add rsp, 8h
	jmp run_method.loop	
.lxor:
	mov rax, [rsp+8h]
	xor [rsp+18h], rax
	add rsp, 10h
	jmp run_method.loop	

%endif
