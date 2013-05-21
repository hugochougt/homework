;访问结构体变量
.386
.model flat, stdcall
include kernel32.inc
includelib kernel32.lib
DATE	STRUCT
	month	BYTE		?
	day	BYTE		?
	year	WORD	?			
DATE ends

POINT	STRUCT
	x	BYTE		?
	y	BYTE		?
POINT ends

RECT		STRUCT
	ltop	POINT	<>
	rbottom	POINT	<>
RECT ends

.data
	yesterday	DATE	<2, 4, 2004>
	rect1	RECT		<>
	
.code
start:
	mov al, yesterday.day	;al = 4
	mov	ebx, offset  yesterday	;取偏移量
	mov al, (DATE PTR [ebx]).month	;al = 2
	
	mov rect1.ltop.x, al
	mov rect1.rbottom.y, al
	invoke	ExitProcess, 0
end start