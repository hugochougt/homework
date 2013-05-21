.386
.model flat,stdcall
option casemap:none

include colorPicker.inc

.code

start:

	invoke GetModuleHandle,NULL
	mov    hInstance,eax
	invoke GetCommandLine
	invoke InitCommonControls
	mov		CommandLine,eax
	invoke WinMain,hInstance,NULL,CommandLine,SW_SHOWDEFAULT
	invoke ExitProcess,eax

WinMain proc hInst:HINSTANCE,hPrevInst:HINSTANCE,CmdLine:LPSTR,CmdShow:DWORD
	LOCAL	wc:WNDCLASSEX
	LOCAL	msg:MSG

	mov		wc.cbSize,sizeof WNDCLASSEX
	mov		wc.style,CS_HREDRAW or CS_VREDRAW
	mov		wc.lpfnWndProc,offset WndProc
	mov		wc.cbClsExtra,NULL
	mov		wc.cbWndExtra,DLGWINDOWEXTRA
	push	hInst
	pop		wc.hInstance
	mov		wc.hbrBackground,COLOR_BTNFACE+1
	mov		wc.lpszMenuName,IDM_MENU
	mov		wc.lpszClassName,offset ClassName
	invoke LoadIcon,NULL,IDI_APPLICATION
	mov		wc.hIcon,eax
	mov		wc.hIconSm,eax
	invoke LoadCursor,NULL,IDC_ARROW
	mov		wc.hCursor,eax
	invoke RegisterClassEx,addr wc
	invoke CreateDialogParam,hInstance,IDD_DIALOG,NULL,addr WndProc,NULL
	invoke ShowWindow,hWnd,SW_SHOWNORMAL
	invoke UpdateWindow,hWnd
	.while TRUE
		invoke GetMessage,addr msg,NULL,0,0
	  .BREAK .if !eax
		invoke TranslateMessage,addr msg
		invoke DispatchMessage,addr msg
	.endw
	mov		eax,msg.wParam
	ret

WinMain endp

WndProc proc hWin:HWND,uMsg:UINT,wParam:WPARAM,lParam:LPARAM
	; 保存光标的坐标
	LOCAL @stPoint:POINT

	LOCAL @hDcShowPic:HDC
	LOCAL @hDcScreen:HDC
	LOCAL @hDcShowColor:HDC
	
	LOCAL @dwDx:dword
	LOCAL @dwDy:dword
	
	LOCAL @colorRect:RECT
	LOCAL @hColorWin:HWND
	LOCAL @dwColor:DWORD
	LOCAL @hBrush:HBRUSH
	LOCAL @hBrushOld:HBRUSH
	
	LOCAL @colorRed:byte
	LOCAL @colorGreen:byte
	LOCAL @colorBlue:byte

	mov		eax,uMsg
	.if eax==WM_INITDIALOG
		; 保存对话框的窗口句柄
		push	hWin
		pop		hWnd
		
		; 设置主窗口的图标
		invoke LoadIcon, hInstance, IDI_WIN_MAIN
		invoke SendMessage, hWnd, WM_SETICON, ICON_BIG, eax
		
		; 设置定时器
		invoke SetTimer, hWnd, NULL, 100, NULL
		
	.elseif eax == WM_TIMER		; 响应定时器的消息
		; 获取当前光标的坐标值
		invoke GetCursorPos, addr @stPoint
		
		; 讲XY坐标显示到对话框中
		invoke SetDlgItemInt, hWnd, IDC_EDT_POSX, @stPoint.x, FALSE
		invoke SetDlgItemInt, hWnd, IDC_EDT_POSY, @stPoint.y, FALSE
	
		; 向XY坐标靠前一点
		mov eax, @stPoint.x
		sub eax, 8
		mov @dwDx, eax
		mov eax, @stPoint.y
		sub eax, 9
		mov @dwDy, eax
		
		; 获取整个屏幕的DC
		invoke GetDC, NULL
		mov @hDcScreen, eax
		
		; 获取显示屏幕定制区域的窗口DC
		invoke GetDlgItem, hWnd, IDC_IMG_SHOWPIC
		invoke GetDC, eax
		mov @hDcShowPic, eax
		
		; 将屏幕制定区域绘制到制定的窗口DC中
		invoke StretchBlt, @hDcShowPic, 0, 0, 112, 94, @hDcScreen, @dwDx, @dwDy, 16, 18, SRCCOPY
	
		; 向图片框绘制一条十字线以便表明鼠标的中心点
		invoke CreatePen, PS_SOLID, 1, 0
		mov @hBrush, eax
		; 在图片框上画一条横线
		invoke MoveToEx, @hDcShowPic, 0, 47, NULL
		invoke LineTo, @hDcShowPic, 112, 47
		; 在图片框上画一条竖线
		invoke MoveToEx, @hDcShowPic, 56, 0, NULL
		invoke LineTo, @hDcShowPic, 56, 94
		
		; 显示当前鼠标指向的颜色
		invoke GetDlgItem, hWnd, IDC_IMG_COLOR
		mov @hColorWin, eax
		invoke GetDC, eax
		mov @hDcShowColor, eax
		
		; 构造显示颜色的图片框的坐标
		mov @colorRect.left, 0
		mov @colorRect.top, 0
		mov @colorRect.right, 112
		mov @colorRect.bottom, 15
		
		; 获取屏幕鼠标所指向点的颜色值
		invoke GetPixel, @hDcScreen, @stPoint.x, @stPoint.y
		mov @dwColor, eax
		
		; 为当前获取的颜色值创建一个实心画刷
		invoke CreateSolidBrush, @dwColor
		mov @hBrush, eax
		
		; 在显示颜色的图片框中填充画刷制定的颜色值
		invoke FillRect, @hDcShowColor, addr @colorRect, @hBrush
	
		; 拆解32位的颜色值到三个字节类型的变量中，然后显示
		mov eax, @dwColor
		mov @colorRed, al
		mov @colorGreen, ah
		ror eax, 16
		mov @colorBlue, al
		
		invoke SetDlgItemInt, hWnd, IDC_EDT_RED, @colorRed, FALSE
		invoke SetDlgItemInt, hWnd, IDC_EDT_GREEN, @colorGreen, FALSE
		invoke SetDlgItemInt, hWnd, IDC_EDT_BLUE, @colorBlue, FALSE
	
	.elseif eax==WM_COMMAND
		mov		eax,wParam
		and		eax,0FFFFh
		.if eax==IDM_FILE_EXIT
			invoke SendMessage,hWin,WM_CLOSE,0,0
		.elseif eax==IDM_HELP_ABOUT
			invoke ShellAbout,hWin,addr AppName,addr AboutMsg,NULL
		.endif
;	.elseif eax==WM_SIZE
	.elseif eax==WM_CLOSE
		invoke DestroyWindow,hWin
	.elseif uMsg==WM_DESTROY
		invoke PostQuitMessage,NULL
	.else
		invoke DefWindowProc,hWin,uMsg,wParam,lParam
		ret
	.endif
	xor    eax,eax
	ret

WndProc endp

end start
