section .data

opcodes:
	dq run_method.loop
	dq opcode_impl.aconst_null
	dq opcode_impl.iconst_m1
	dq opcode_impl.iconst_0
	dq opcode_impl.iconst_1
	dq opcode_impl.iconst_2
	dq opcode_impl.iconst_3
	dq opcode_impl.iconst_4
	dq opcode_impl.iconst_5
	dq opcode_impl.lconst_0
	dq opcode_impl.lconst_1
	dq opcode_impl.fconst_0
	dq opcode_impl.fconst_1
	dq opcode_impl.fconst_2
	dq opcode_impl.dconst_0
	dq opcode_impl.dconst_1
	dq opcode_impl.bipush
	dq opcode_impl.sipush
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.load
	dq opcode_impl.wload
	dq opcode_impl.load
	dq opcode_impl.wload
	dq opcode_impl.load
	dq opcode_impl.load_0
	dq opcode_impl.load_1
	dq opcode_impl.load_2
	dq opcode_impl.load_3
	dq opcode_impl.wload_0
	dq opcode_impl.wload_1
	dq opcode_impl.wload_2
	dq opcode_impl.wload_3
	dq opcode_impl.load_0
	dq opcode_impl.load_1
	dq opcode_impl.load_2
	dq opcode_impl.load_3
	dq opcode_impl.wload_0
	dq opcode_impl.wload_1
	dq opcode_impl.wload_2
	dq opcode_impl.wload_3
	dq opcode_impl.load_0
	dq opcode_impl.load_1
	dq opcode_impl.load_2
	dq opcode_impl.load_3
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.store
	dq opcode_impl.wstore
	dq opcode_impl.store
	dq opcode_impl.wstore
	dq opcode_impl.store
	dq opcode_impl.store_0
	dq opcode_impl.store_1
	dq opcode_impl.store_2
	dq opcode_impl.store_3
	dq opcode_impl.wstore_0
	dq opcode_impl.wstore_1
	dq opcode_impl.wstore_2
	dq opcode_impl.wstore_3
	dq opcode_impl.store_0
	dq opcode_impl.store_1
	dq opcode_impl.store_2
	dq opcode_impl.store_3
	dq opcode_impl.wstore_0
	dq opcode_impl.wstore_1
	dq opcode_impl.wstore_2
	dq opcode_impl.wstore_3
	dq opcode_impl.store_0
	dq opcode_impl.store_1
	dq opcode_impl.store_2
	dq opcode_impl.store_3
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.pop
	dq opcode_impl.pop2
	dq opcode_impl.dup
	dq opcode_impl.dup_x1
	dq opcode_impl.dup_x2
	dq opcode_impl.dup2
	dq opcode_impl.dup2_x1
	dq opcode_impl.dup2_x2
	dq opcode_impl.swap
	dq opcode_impl.iadd
	dq opcode_impl.ladd
	dq opcode_impl.fadd
	dq opcode_impl.dadd
	dq opcode_impl.isub
	dq opcode_impl.lsub
	dq opcode_impl.fsub
	dq opcode_impl.dsub
	dq opcode_impl.imul
	dq opcode_impl.lmul
	dq opcode_impl.fmul
	dq opcode_impl.dmul
	dq opcode_impl.idiv
	dq opcode_impl.ldiv
	dq opcode_impl.fdiv
	dq opcode_impl.ddiv
	dq opcode_impl.irem
	dq opcode_impl.lrem
	dq opcode_impl.frem
	dq opcode_impl.drem
	dq opcode_impl.ineg
	dq opcode_impl.lneg
	dq opcode_impl.fneg
	dq opcode_impl.dneg
	dq opcode_impl.ishl
	dq opcode_impl.lshl
	dq opcode_impl.ishr
	dq opcode_impl.lshr
	dq opcode_impl.iushr
	dq opcode_impl.lushr
	dq opcode_impl.iand
	dq opcode_impl.land
	dq opcode_impl.ior
	dq opcode_impl.lor
	dq opcode_impl.ixor
	dq opcode_impl.lxor
	dq opcode_impl.iinc
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.ireturn
	dq opcode_impl.lreturn
	dq opcode_impl.freturn
	dq opcode_impl.dreturn
	dq run_method.loop
	dq opcode_impl.return
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.end

constants:
.float_0:
	dd 0.0
.float_1:
	dd 1.0
.float_2:
	dd 2.0
.double_0:
	dq 0.0
.double_1:
	dq 1.0
	
section .text
	global run_method

run_method:
	push rbp
	mov rbp, rsp

	;; store bytecode pointer
	mov r10, rdx

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
.iinc:
	mov bl, [r10]
	mov al, [r10+1]
	movsx rax, al
	add [r11+rbx*8h], rax
	add r10, 2h
	jmp run_method.loop	
	
.return:
	xor rax,rax
	jmp run_method.end
.ireturn:
	pop rax
	jmp run_method.end
.lreturn:
	pop rax
	pop rax
	jmp run_method.end
.freturn:
	xorps xmm0, xmm0
	movss xmm0, [rsp]
	add rsp, 8h
	jmp run_method.end
.dreturn:
	xorps xmm0, xmm0
	movlps xmm0, [rsp+8h]
	add rsp, 10h
	jmp run_method.end