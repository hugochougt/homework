#include <stdio.h>
#include <stdlib.h>
#include <iostream.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>

#define PA 0xc000
#define PB 0xc001
#define C0 0xc003

int main(void)
{
	//__int8 AL;
	int a=0,b,c,d,e;
	__int16 A[10]={0x0c0,0x0f9,0x0a4,0x0b0,0x99,0x92,0x82,0xf8,0x80,0x98};

	_outp(C0,0x80);
	
	while(1)
	{
		for(;a<=9999;a++)
		{
			if (kbhit())
				break;
			b=a%10;			//个位数
			c=(a/10)%10;	//10位数
			d=(a/100)%10;	//100位数
			e=(a/1000)%10;	//1000位数

			_outp(PB,0xFE);
			_outp(PA,A[b]);
			Sleep(1);
			_outp(PB,0xFD);
			_outp(PA,A[c]);
			Sleep(1);
			_outp(PB,0xFB);
			_outp(PA,A[d]);
			Sleep(1);
			_outp(PB,0xF7);
			_outp(PA,A[e]);
			
			printf("%d\n",a);
			Sleep(2);
		}
		a=0;
	}
	return 0;

}