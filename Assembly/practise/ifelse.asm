;显示星期几
.386
.model flat, stdcall
option casemap:none

include windows.inc
include kernel32.inc
includelib kernel32.lib
include user32.inc
includelib user32.lib

.data
	num	dd	?	;用于保存余数
	Caption1	db	"分支程序实例", 0
	Caption2	db	"出错", 0
	szWarning db	"出错，数据不在1至7之间！", 0
	;英文名称定义称等长，以便于查表
	week	db	"monday   ", 0
			db	"tuesday  ", 0
			db	"wednesday", 0
			db	"thursday ", 0
			db	"friday   ", 0
			db	"saturday ", 0
			db	"sunday   ", 0
			
.code
start:
	xor	edx, edx
	mov	num, 7
	div num
	.if	edx == 1
		mov ebx, 0
	.elseif 	edx == 2
		mov ebx, 10
	.elseif	edx == 3
		mov ebx, 20
	.elseif	edx == 4
		mov ebx, 30
	.elseif	edx == 5
		mov ebx, 40
	.elseif	edx == 6
		mov ebx, 50
	.elseif	edx == 0
		mov ebx, 60
	.else
		invoke MessageBox, NULL, addr szWarning, offset Caption2, MB_OK
	.endif
	mov eax,offset week
	add	eax, ebx
	invoke MessageBox, NULL, eax, offset Caption1, MB_OK
	invoke ExitProcess, 0
end start