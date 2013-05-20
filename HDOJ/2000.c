#include "stdio.h"

int main(void)
{
	char a,b,c,t;
	void swap(char *p,char *q);
	while(scanf("%c%c%c%*c",&a,&b,&c)!=EOF)
	{	
		
		if(b<a)
			{t=a;a=b;b=t;}
		if(b>c)
			{t=b;b=c;c=t;}
		if(a>b)
			{t=a;a=b;b=t;}
		printf("%c %c %c\n",a,b,c);
	}
	return 0;
}
