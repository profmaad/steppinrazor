%ifndef STEPPINRAZOR_OPCODE_IMPL_METHOD_H
%define STEPPINRAZOR_OPCODE_IMPL_METHOD_H
	
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
.areturn:
	pop rax
	jmp run_method.end

%endif
