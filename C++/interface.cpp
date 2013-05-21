#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x);
unsigned leftrot(unsigned x);
unsigned mid2side(unsigned x);
unsigned side2mid(unsigned x);
int wordlength(void);

int main()
{
	int x;
	scanf("%d", &x);
	printf("%d\n", leftrot(x));
	printf("%d\n", rightrot(x));
	system("pause");
	return 0;
}

int wordlength(void)
{
	int i;
	unsigned v = (unsigned)~0;
	
	for(i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}

unsigned rightrot(unsigned x)
{
	int rbit;
	rbit = (x & 1) << (wordlength() - 1);
	x = x >> 1;
	x = x | rbit;
	return x; 
}

unsigned leftrot(unsigned x)
{
	int lbit;
	lbit = x >> (wordlength() - 1);
	x = x << 1;
	x = x | lbit;
	return x;
}
