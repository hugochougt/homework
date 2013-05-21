;整数转换程序
.386
.model flat, stdcall
option casemap:none

include windows.inc
include kernel32.inc
includelib kernel32.lib
include user32.inc
includelib user32.lib

.data
	szCaption	db	'conver num to string', 0
	szResult	db	6 dup(0)
	
.code
_Translate	proc	para1:DWORD, para2:DWORD
	
	LOCAL	_iNum
	LOCAL	_iTemp
	LOCAL	_szTemp[256]:BYTE
	
	mov	eax, para1
	mov _iNum, eax
	mov _iTemp, 10
	lea ebx, _szTemp
	
	xor ecx, ecx
	
	.while	_iNum
			xor edx, edx
			mov eax, _iNum
			div _iTemp
			mov _iNum, eax
			;mov eax, _iNum
			add al, 48
			mov BYTE PTR [ebx], dl
			inc ebx
			inc ecx
	.endw 
	
	mov eax, para2
	mov BYTE PTR [eax+ecx], 0
	lea ebx, _szTemp
	
	.repeat
		mov dl, BYTE PTR [ebx]
		mov BYTE PTR [eax+ecx-1], dl
		inc ebx
	.untilcxz
	
	ret

_Translate endp

start:
	mov eax, 12345678
	invoke _Translate, eax, offset szResult
	invoke MessageBox, NULL, offset szResult, offset szCaption, MB_OK
	invoke ExitProcess, 0
end start