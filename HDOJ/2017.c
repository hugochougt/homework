#include <ctype.h>
#include "stdio.h"
int main(void)
{
	char s;
	int n,count;
	scanf("%d%*c",&n);
	while(n--)
	{
		count=0;
		do{
			s=getchar();
			if(isdigit(s))
				count++;
		}while(s!='\n');
		printf("%d\n",count);
	}
	return 0;
}