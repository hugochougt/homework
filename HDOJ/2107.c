#include "stdio.h"
int main(void)
{
	int N,ac,max,i;
	while(scanf("%d",&N),N)
	{
		max=-1;
		
		for(i=0;i<N;i++)
		{
			scanf("%d",&ac);
			
			if(ac>max)
				
				max=ac;	
		}
		printf("%d\n",max);
	}    
	return 0;
}