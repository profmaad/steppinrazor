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
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.bipush
	dq opcode_impl.sipush
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.load
	dq opcode_impl.wload
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.load
	dq opcode_impl.load_0
	dq opcode_impl.load_1
	dq opcode_impl.load_2
	dq opcode_impl.load_3
	dq opcode_impl.wload_0
	dq opcode_impl.wload_1
	dq opcode_impl.wload_2
	dq opcode_impl.wload_3
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.load_1
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
	dq opcode_impl.store
	dq opcode_impl.wstore
	dq run_method.loop
	dq run_method.loop
	dq run_method.loop
	dq opcode_impl.store_0
	dq opcode_impl.store_1
	dq opcode_impl.store_2
	dq opcode_impl.store_3
	dq opcode_impl.wstore_0
	dq opcode_impl.wstore_1
	dq opcode_impl.wstore_2
	dq opcode_impl.wstore_3
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
	dq opcode_impl.iadd
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
	dq opcode_impl.ireturn
	dq opcode_impl.lreturn
	dq opcode_impl.freturn
	dq run_method.loop
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
	lea rax, [r11+rax*8h]
	pop rbx
	mov [rax], rbx
	add r10, 1h
	jmp run_method.loop
.wstore:
	mov al, [r10]
	lea rax, [r11+rax*8h]
	pop rbx
	pop rbx
	mov [rax], rbx
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
	
.iadd:
	pop rax
	pop rbx
	add eax, ebx
	push rax
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