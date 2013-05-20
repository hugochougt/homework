/* 计算计算机所使用的字长 */

#include<stdio.h>

int main()
{
	int wordlength(void);
	
	printf("Wordlength: %d\n", wordlength());
	return 0;
}

/* wordlength: computes word length of the machine */
int wordlength(void)
{
	int i;
	unsigned v = (unsigned) ~0;
	
	for(i = 1; (v = v >> 1) > 0; i++)
		;
	return i;
}