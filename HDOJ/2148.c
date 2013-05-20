#include "stdio.h"

int main(void)
{
	int T,N,K,s[101],i,count;
	
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%d%d",&N,&K);
		
		for(i=1;i<=N;i++)
			scanf("%d",&s[i]);
		
		count=0;
		
		for(i=1;i<=N;i++)
		{
			if(s[i]>s[K]&&i!=K)
				count++;	
		}
		printf("%d\n",count);
	}    
	return 0;
}