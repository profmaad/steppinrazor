%ifndef STEPPINRAZOR_OPCODE_IMPL_JUMP_H
%define STEPPINRAZOR_OPCODE_IMPL_JUMP_H
	
.ifeq:
	pop rax
	cmp eax, 0h
	je .goto
	add r10, 2h
	jmp run_method.loop
.ifne:
	pop rax
	cmp eax, 0h
	jne .goto
	add r10, 2h
	jmp run_method.loop
.iflt:
	pop rax
	cmp eax, 0h
	jl .goto
	add r10, 2h
	jmp run_method.loop
.ifge:
	pop rax
	cmp eax, 0h
	jge .goto
	add r10, 2h
	jmp run_method.loop
.ifgt:
	pop rax
	cmp eax, 0h
	jg .goto
	add r10, 2h
	jmp run_method.loop
.ifle:
	pop rax
	cmp eax, 0h
	jle .goto
	add r10, 2h
	jmp run_method.loop

.if_icmpeq:
	pop rax
	pop rbx
	cmp eax, ebx
	je .goto
	add r10, 2h
	jmp run_method.loop
.if_icmpne:
	pop rax
	pop rbx
	cmp eax, ebx
	jne .goto
	add r10, 2h
	jmp run_method.loop
.if_icmplt:
	pop rax
	pop rbx
	cmp ebx, eax
	jl .goto
	add r10, 2h
	jmp run_method.loop
.if_icmpge:
	pop rax
	pop rbx
	cmp ebx, eax
	jge .goto
	add r10, 2h
	jmp run_method.loop
.if_icmpgt:
	pop rax
	pop rbx
	cmp ebx, eax
	jg .goto
	add r10, 2h
	jmp run_method.loop
.if_icmple:
	pop rax
	pop rbx
	cmp ebx, eax
	jle .goto
	add r10, 2h
	jmp run_method.loop

.if_acmpeq:
	pop rax
	pop rbx
	cmp rax, rbx
	je .goto
	add r10, 2h
	jmp run_method.loop
.if_acmpne:
	pop rax
	pop rbx
	cmp rax, rbx
	jne .goto
	add r10, 2h
	jmp run_method.loop
	
.goto:
	mov ax, [r10]
	xchg al, ah
	movsx rax, ax
	add r10, rax
	sub r10, 1h
	jmp run_method.loop

.jsr:
	mov rax, [r10]
	add rax, 2h
	push rax
	jmp opcode_impl.goto
.ret:
	mov al, [r10]
	mov r10, [r11+rax*8h]	
	jmp run_method.loop

.tableswitch:
	xor rax, rax
	mov rax, r10
	sub rax, [rbp-8h]
	xor rdx, rdx
	mov rbx, 4h
	div rbx
	cmp rdx, 0h
	je .tableswitch.2
	mov rax, rdx
	mov rdx, 4h
	sub rdx, rax
.tableswitch.2:
	mov eax, DWORD [r10+rdx]
	bswap eax
	mov ebx, DWORD [r10+rdx+4h]
	bswap ebx
	mov ecx, DWORD [r10+rdx+8h]
	bswap ecx
	lea rsi, [r10+rdx+0xC]
	sub r10, 1h
	pop rdx
	cmp edx, ebx
	jl .tableswitch.default
	cmp edx, ecx
	jg .tableswitch.default
	sub rdx, rbx
	mov eax, DWORD [rsi+rdx*4h]
	bswap eax
	cdqe
.tableswitch.default:
	add r10, rax
	jmp run_method.loop

.lookupswitch:
	xor rax, rax
	mov rax, r10
	sub rax, [rbp-8h]
	xor rdx, rdx
	mov rbx, 4h
	div rbx
	cmp rdx, 0h
	je .lookupswitch.2
	mov rax, rdx
	mov rdx, 4h
	sub rdx, rax
.lookupswitch.2:
	mov eax, DWORD [r10+rdx]
	bswap eax
	mov ebx, DWORD [r10+rdx+4h]
	bswap ebx
	lea rdx, [r10+rdx+8h]
	sub r10, 1h
	pop rcx
	bswap ecx
.lookupswitch.loop:
	test ebx, ebx
	je .lookupswitch.default
	cmp ecx, DWORD [rdx]
	je .lookupswitch.match
	dec ebx	
	add rdx, 8h
	jmp .lookupswitch.loop
.lookupswitch.match:
	mov eax, DWORD [rdx+4h]
	bswap eax
	cdqe
.lookupswitch.default:
	add r10, rax
	jmp run_method.loop

.ifnull:
	pop rax
	cmp rax, 0h
	je .goto
	add r10, 2h	
	jmp run_method.loop
.ifnonnull:
	pop rax
	cmp rax, 0h
	jne .goto
	add r10, 2h	
	jmp run_method.loop

.goto_w:
	mov eax, DWORD [r10]
	bswap eax
	cdqe
	add r10, rax
	sub r10, 1h
	jmp run_method.loop
.jsr_w:
	mov rax, [r10]
	add rax, 2h
	push rax
	jmp opcode_impl.goto_w

%endif
