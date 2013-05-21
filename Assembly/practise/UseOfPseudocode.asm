.386
.model flat, stdcall
option casemap:none
include kernel32.inc
includelib kernel32.lib
include windows.inc
include user32.inc
includelib user32.lib

.data
szString1	db	"This is a.", 0
szString2	db	256 dup(0)

.code
start:
	mov esi, offset szString1
	mov edi, offset szString2
	
	.while TRUE
		mov AL, [esi]
		.break .if AL == 0
		.if AL == 'a'
			mov Al, 'b'
			mov [edi], AL
			inc esi
			inc edi
			.continue
		.endif
		mov [edi], AL
		inc edi
		inc esi
	.endw
	invoke MessageBox, NULL, addr szString1, addr szString2, MB_OK
	invoke ExitProcess, 0
end start