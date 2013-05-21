;定义局部变量
.386
.model flat, stdcall
include kernel32.inc
includelib kernel32.lib
.code
start:
	call MyProc
	invoke ExitProcess, 0
	
	MyProc	proc
	LOCAL	lca1:byte
	LOCAL	buffer[12]:byte
	LOCAL	lca2, lca3
	
	MOV	AL, lca1
	RET
	
	MyProc endp
	
end start