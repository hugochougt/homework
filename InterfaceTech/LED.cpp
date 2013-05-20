#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include <iostream.h>

#define PA 0xc000
#define PB 0xc001
#define PORT 0xc003

int main()
{
	int digit[] = {0x0c0,0x0f9,0x0a4,0x0b0,0x99,0x92,0x82,0xf8,0x80,0x98};
	int a = 0, b = 0, c = 0, d = 0, tmp, i;
	_outp(PORT, 0x80);

	while(1){
		for(int i = 0; i <= 9999; i++){
			if(kbhit()) break;
			tmp = i;

			a = tmp % 10;//个位
			tmp /= 10;

			b = tmp % 10;//十位

			tmp /= 10;
			c = tmp % 10;//百位

			tmp /= 10;
			d = tmp % 10;//千位
			for(int j = 0; j <= 8; j++){
				_outp(PB, 0xFE);
				_outp(PA, digit[a]);
				Sleep(1);
				_outp(PB, 0xFD);
				_outp(PA, digit[b]);
				Sleep(1);
				_outp(PB, 0xFB);
				_outp(PA, digit[c]);
				Sleep(1);
				_outp(PB, 0xF7);
				_outp(PA, digit[d]);
				Sleep(1);
			}
			printf("%d\n", i);
			Sleep(1);
		}
	}
	return 0;
}