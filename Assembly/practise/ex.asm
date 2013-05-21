.386
.model flat, stdcall
option casemap:none

include kernel32.inc
includelib kernel32.lib
include windows.inc
include user32.inc
includelib user32.lib

.data
 	X Db '0123H',30h,48,0dh,0ah," 2A3EH,89DFH",0 
       	Y  Dd  "1234",0
      	Z  dw  '12',3132H,0
       	CUNT   EQU  $-Z
       	aa db  CUNT+48,0
       	bb db 8 dup( '?',20h,2 dup('A',20h)),0
       	CUNT1   EQU  $-bb
       	cc db  CUNT1,0
.code
start:
  
	invoke	MessageBox,NULL, offset X,offset Y,1
	invoke	MessageBox,NULL, offset Z,offset aa,1 
	invoke 	MessageBox,NULL, offset bb,offset cc,1
	invoke	ExitProcess, 0
end start
