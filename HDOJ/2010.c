#include <stdio.h>

int main(void)
{
	int a[]={153,370,371,407},i,m,n,count;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		count=0;
		
		for(i=0;i<4;i++)
		{
			if(a[i]>=m&&a[i]<=n)
				printf(count++?" %d":"%d",a[i]);
		}	
		printf(count?"\n":"no\n");
	} 
	return 0;
}