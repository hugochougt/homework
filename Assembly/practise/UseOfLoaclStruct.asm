;使用局部结构体变量
APIcall	proc parameter1:DWORD, parameter2:DWORD, ppoi:DWORD
	
	mov eax, ppoi	;ppoi是指向POINT结构体变量的指针
	mov [eax], BYTE PTR 10
	mov [eax+1], BYTE PTR 12
	ret

APIcall endp

APIcall	proc parameter1:DWORD, parameter2:DWORD, ppoi:DWORD
	
	mov eax, ppoi
	mov (POINT PTR [eax]).x, 10
	mov (POINT PTR [eax]).y, 12
	ret

APIcall endp