%ifndef STEPPINRAZOR_OPCODE_IMPL_COMPARISON_H
%define STEPPINRAZOR_OPCODE_IMPL_COMPARISON_H

.lcmp:
	mov rax, [rsp+18h]
	cmp rax, [rsp+8h]
	jg .lcmp.greater
	jl .lcmp.less
	mov QWORD [rsp+18h], 0h
	jmp .lcmp.end
.lcmp.greater:
	mov QWORD [rsp+18h], 1h
	jmp .lcmp.end
.lcmp.less:
	mov QWORD [rsp+18h], -1h
.lcmp.end:
	add rsp, 18h
	jmp run_method.loop

.fcmpl:
	movss xmm0, [rsp+8h]
	ucomiss xmm0, [rsp]
	ja .fcmp.greater
	jb .fcmp.less
	je .fcmp.equal
	mov DWORD [rsp+8h], -1h
	jmp .fcmp.end
.fcmpg:
	movss xmm0, [rsp+8h]
	ucomiss xmm0, [rsp]
	ja .fcmp.greater
	jb .fcmp.less
	je .fcmp.equal
	mov DWORD [rsp+8h], 1h
	jmp .fcmp.end
.fcmp.greater:
	mov DWORD [rsp+8h], 1h
	jmp .fcmp.end	
.fcmp.less:
	mov DWORD [rsp+8h], -1h
	jmp .fcmp.end	
.fcmp.equal:
	mov DWORD [rsp+8h], 0h
.fcmp.end:
	add rsp, 8h
	jmp run_method.loop

.dcmpl:
	movsd xmm0, [rsp+18h]
	ucomisd xmm0, [rsp+8h]
	ja .dcmp.greater
	jb .dcmp.less
	je .dcmp.equal
	mov QWORD [rsp+18h], -1h
	jmp .dcmp.end
.dcmpg:
	movsd xmm0, [rsp+18h]
	ucomisd xmm0, [rsp+8h]
	ja .dcmp.greater
	jb .dcmp.less
	je .dcmp.equal
	mov QWORD [rsp+18h], 1h
	jmp .dcmp.end
.dcmp.greater:
	mov QWORD [rsp+18h], 1h
	jmp .dcmp.end	
.dcmp.less:
	mov QWORD [rsp+18h], -1h
	jmp .dcmp.end	
.dcmp.equal:
	mov QWORD [rsp+18h], 0h
.dcmp.end:
	add rsp, 18h
	jmp run_method.loop

%endif
