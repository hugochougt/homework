.386
.model flat,stdcall
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Include 文件定义
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include windows.inc
include kernel32.inc
includelib kernel32.lib
include user32.inc
includelib user32.lib
include masm32.inc
includelib masm32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 数据段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.data
	szCaption db	"显示数组y:",0
	x db 16 dup(0)
	y db 16 dup(0), 0
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 代码段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 10进制到16进制转换子程序
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
_Translate proc near
	
	AND BL,0fh
	OR BL,30h
	CMP BL,39h
	JBE htoend
	ADD BL,7
htoend:	ret

_Translate endp

start:
   	MOV ECX, 15
   	
 s1:	MOV x[ECX], CL
   	loop s1
   	
   	ADD ECX, 16
   	MOV EAX, offset x
   	MOV EDX, offset y
   	
 s2: 	MOV BL,[EAX+ECX-1]
   	call _Translate
   	MOV [EDX],BL
   	inc EDX
   	dec ECX
   	CMP ECX,0
   	JNE s2
   	
   	invoke MessageBox, NULL, addr y, addr szCaption, MB_OK
   	invoke ExitProcess,0
end start








