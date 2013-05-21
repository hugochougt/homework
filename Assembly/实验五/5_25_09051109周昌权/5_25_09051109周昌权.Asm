.386
.model flat, stdcall
option casemap:none

include windows.inc
include user32.inc
includelib user32.lib
include kernel32.inc
includelib kernel32.lib
include gdi32.inc
includelib gdi32.lib

IDD_DIALOG_MAIN	equ	311
IDC_PICTURE		equ	310
IDC_BUTTON_SHOW		equ	1000
IDC_BUTTON_DELETE	equ	1001
IDM_EXIT	equ		40001

.data?
hInstance	dd	?
hBitmap	dd	?

.code
DlgProc	proc	hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	
	.if uMsg == WM_INITDIALOG
		invoke LoadBitmap, hInstance, 115
		mov hBitmap, eax
		invoke SendDlgItemMessage, hWnd, IDC_PICTURE, STM_SETIMAGE, IMAGE_BITMAP, hBitmap
	.elseif uMsg == WM_COMMAND
		mov eax, wParam
		movzx eax, ax
		.if eax == IDC_BUTTON_SHOW
			invoke LoadBitmap, hInstance, 115
			mov hBitmap, eax
			invoke SendDlgItemMessage, hWnd, IDC_PICTURE, STM_SETIMAGE, IMAGE_BITMAP, hBitmap
		.elseif eax == IDC_BUTTON_DELETE
			invoke SendDlgItemMessage, hWnd, IDC_PICTURE, STM_SETIMAGE, IMAGE_BITMAP, NULL
			invoke DeleteObject, hBitmap
		.elseif eax == IDM_EXIT
			invoke DeleteObject, hBitmap
			invoke EndDialog, hWnd, NULL
		.endif
	.elseif uMsg == WM_CLOSE
		invoke DeleteObject, hBitmap
		invoke EndDialog, hWnd, NULL
	.else
		mov eax, FALSE
		ret
	.endif
	mov eax, TRUE
	ret

DlgProc endp

start:
	invoke GetModuleHandle, NULL
	mov hInstance, eax
	invoke DialogBoxParam, hInstance, IDD_DIALOG_MAIN, NULL, DlgProc, NULL
	invoke ExitProcess, NULL
end start