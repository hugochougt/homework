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
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 数据段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.data
A1 db 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15
B1 db 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20
C1 db 30 dup(0)
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 代码段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
start:
	MOV EAX, offset A1
	MOV EDI, 15
	MOV EDX, offset C1
s1: 	MOV EBX, offset B1
       	MOV CL, 20
s2: 	MOV CH, [EAX]
       	CMP CH, [EBX]
       	JNE l1
       	MOV [EDX],CH
       	INC EDX
       	JMP l2
l1: 	INC EBX
        DEC CL
        CMP CL,0
        JNE s2
l2: 	INC EAX
        DEC EDI
        CMP EDI,0
        JNE s1
	invoke ExitProcess,0
end start