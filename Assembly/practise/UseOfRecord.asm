;记录变量的完整示例，p137
.386
.model flat, stdcall
option casemap:none
include kernel32.inc
includelib kernel32.lib

MYRECORD	RECORD	FLAGA:2, FLAGB:3, FLAGC:3

.data
rMRVal	MYRECORD	<1, 3, 1>
wFLAGA	EQU	WIDTH FLAGA	; wFLAGA = 2
wFLAGB	EQU	WIDTH FLAGB	; wFLAGB = 3
wFLAGC	EQU	WIDTH FLAGC	; wFLAGC = 3
wMYRECORD	EQU	WIDTH MYRECORD	;wMYRECORD = 8

.code
start:
	MOV BL, MYRECORD
	MOV AL, rMRVal
	MOV AH, AL
	AND AL, NOT MASK FLAGA
	MOV CL, FLAGB
	SHR AH, CL
	INC AH
	SHL AH, CL
	AND AH, MASK FLAGB
	
	invoke ExitProcess, 0
end start