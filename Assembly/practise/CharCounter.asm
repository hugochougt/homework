;字符统计程序
.386
.model flat, stdcall
option casemap:none

include windows.inc
include kernel32.inc
includelib kernel32.lib
include user32.inc
includelib user32.lib

.data
	szText	db	'welcome to use assembly language', 0
	Caption	db	'统计字符"s"出现次数', 0
	szBuffer	db	256 dup(0)
	
.code
_Translate	proc	para1:DWORD, para2:DWORD
	
	LOCAL	_iNum
	LOCAL	_iTemp
	LOCAL	_szTemp[256]:BYTE
	
	mov eax, para1
	mov _iNum, eax
	mov _iTemp, 10
	lea ebx, _szTemp
	xor ecx, ecx
	
	.while _iNum
		xor edx, edx
		mov eax, _iNum
		div _iTemp
		mov _iNum, eax
		add dl, 48
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
	mov ecx, 0
	mov ebx, offset szText
	mov al, [ebx]
	.while	( al != 0 )
		.if al == 's'
			inc ecx
		.endif
		inc ebx
		mov al, [ebx]
	.endw
	invoke _Translate, ecx, addr szBuffer
	invoke MessageBox, NULL, offset szBuffer, offset Caption, MB_OK
	invoke ExitProcess, 0
end start