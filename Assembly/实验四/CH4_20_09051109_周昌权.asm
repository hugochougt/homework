.386
.model flat, stdcall
option casemap:none

include kernel32.inc
includelib kernel32.lib

.data
mybyte	db	0ffh
chenbei	dw	11h, 22h, 33h

.code
good:
	mov eax, offset chenbei
	mov ebx, type	chenbei
	mov ecx, lengthof	chenbei
	mov edx, sizeof	chenbei
	
	invoke ExitProcess, 0
end good