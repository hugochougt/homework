#include <stdio.h>

int main(void)
{
	int M,K,day;
	
	while(scanf("%d%d",&M,&K),M||K)
	{
		for(day=0;M>0;day++,M--)
		
			if(0==day%K)
		
				M++;	
				
		printf("%d\n",day-1);
	}    
	return 0;
}