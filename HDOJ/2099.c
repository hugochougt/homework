#include "stdio.h"
int main(void)
{
	int i,a,b,count;
	while(scanf("%d%d",&a,&b),a||b)
	{
		count=0;
		
		for(i=0;i<100;i++)
		{
			if(!((a*100+i)%b))
				printf(count++?" %02d":"%02d",i);
		}
		
		printf("\n");
	} 
	return 0;
}