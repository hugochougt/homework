.386
.model flat, stdcall
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; Include 文件定义
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
include	kernel32.inc
includelib	kernel32.lib
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 数据段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.data
	x	dw	15
 	y	dw 	16
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
; 代码段
;>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
.code
start:
   ;.....立即寻址。。。。。。。。。。。	
   mov	ax, 1234H
   ;.....寄存器寻址。。。。。。。。。。。	
   MOV	EAX, EBX
   ;.....直接寻址。。。。。。。。。。。	
 
   MOV AX,x                 ;MOV AX,WORD PTR DS:[403000]
   MOV BX,[x]                ;MOV BX,WORD PTR DS:[403000]
   ;.....立即寻址。。。。。。。。。。。	
   MOV ESI, offset x         ;MOV ESI,1xunzhi.00403000
   mov EDI, offset y          ;MOV EDI,1xunzhi.00403002
   ;.....寄存器间接寻址。。。。。。。。。。。	 
   MOV Ah,[ESI]                 ;MOV AX,WORD PTR DS:[ESI]
   MOV BX,[EDI]                 ;MOV BX,WORD PTR DS:[EDI]
   mov [esi],bx                  ;MOV WORD PTR DS:[ESI],BX
   mov [edi],ax                  ;MOV WORD PTR DS:[EDI],AX
   ;.....立即寻址。。。。。。。。。。。	
   MOV ESI,2                     
   MOV Ebx,offset y              ;MOV EBX,1xunzhi.00403002
   ;。。。。。寄存器相对寻址。。。。。。。。。。。。。。
   MOV 	AX,x[ESI]                ;MOV AX,WORD PTR DS:[ESI+403000]
   mov ebx,offset x              ;MOV EBX,1xunzhi.00403000
   ;。。。。。基址变址寻址 。。。。。。。。。。。。 
   MOV 	AX,[EBX][ESI]              ;MOV AX,WORD PTR DS:[ESI+EBX]
   ;.....立即寻址。。。。。。。。。。。	
   MOV Ebx,1 
   MOV Edi,1 
   ;。。。。。。。相对基址变址寻址方式 。。。。。。
   MOV	AX,x[EBX][EDI]   ;MOV AX,WORD PTR DS:[EDI+EBX+403000]
   ;.....立即寻址。。。。。。。。。。。	
   MOV Esi,1 
   ;...............比例变址寻址....................
   MOV  AX,x[ESI*2]     ;MOV AX,WORD PTR DS:[ESI*2+403000]
   ;.....立即寻址。。。。。。。。。。。
   MOV 	EBP, offset x    ;MOV EBP,1xunzhi.00403000
   ;...............基址比例变址寻址................ 
   MOV 	CX, [EBP] [ESI*2]   ;MOV CX,WORD PTR SS:[EBP+ESI*2]
   ;............................................
   invoke  ExitProcess,0

end start
