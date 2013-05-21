.386
.model flat, stdcall
option casemap:none
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Include 文件定义
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include windows.inc
include kernel32.inc
includelib kernel32.lib
include user32.inc
includelib user32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 数据段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.data
	szCaption	db	'convert num to string', 0
	szResult	db	6 dup(0)
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 代码段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
_Translate	proc	para1:DWORD, para2:DWORD
	
	local	_iNum	;用于临时保存被除数
	local	_iTemp	;用于临时保存除数
	local	_szTemp[256]:BYTE	;用于保存逆序ASCII码
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 初始化
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	
	mov eax, para1
	mov _iNum, eax
	mov _iTemp, 16
	lea ebx, _szTemp	;把整数转换的逆序保存到临时变量_szTemp
	xor ecx, ecx		;用于记录被转换的整数共有几位
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 在while循环中把被转换的整数循环除16， 把得到的余数
; 转换成ASCII码，并保存到_szTemp临时变量中。
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>	
	.while _iNum
		xor edx, edx
		mov eax, _iNum
		div _iTemp
		mov _iNum, eax
		.if dl < 10
			add dl, 48
		.else
			add dl, 55
		.endif
		mov BYTE PTR [ebx], dl
		inc ebx
		inc ecx
	.endw
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 用一个repeat循环把逆序保存的ASCII码转换为顺序保存的ASCII码
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
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
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
start:
	mov eax, 31A6F1h
	invoke _Translate, eax, offset szResult
	invoke MessageBox, NULL, offset szResult, offset szCaption, MB_OK
	invoke ExitProcess, 0
end start