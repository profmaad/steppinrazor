%ifndef STEPPINRAZOR_OPCODE_IMPL_STACK_H
%define STEPPINRAZOR_OPCODE_IMPL_STACK_H

.pop:
	pop rax
	jmp run_method.loop
.pop2:
	pop rax
	pop rax
	jmp run_method.loop

.dup:
	pop rax
	push rax
	push rax
	jmp run_method.loop
.dup_x1:
	pop rax
	pop rbx
	push rax
	push rbx
	push rax
	jmp run_method.loop
.dup_x2:
	pop rax
	pop rbx
	pop rcx
	push rax
	push rcx
	push rbx
	push rax
	jmp run_method.loop
.dup2:
	pop rax
	pop rbx
	push rbx
	push rax
	push rbx
	push rax
	jmp run_method.loop
.dup2_x1:
	pop rax
	pop rbx
	pop rcx
	push rbx
	push rax
	push rcx
	push rbx
	push rax
	jmp run_method.loop
.dup2_x2:
	pop rax
	pop rbx
	pop rcx
	pop rdx
	push rbx
	push rax
	push rdx
	push rcx
	push rbx
	push rax
	jmp run_method.loop

.swap:
	pop rax
	pop rbx
	push rax
	push rbx
	jmp run_method.loop

%endif
