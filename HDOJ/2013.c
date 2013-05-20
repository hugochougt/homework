#include "stdio.h"
int main(void)
{
	int n,i,t;
	while(scanf("%d",&n)!=EOF)
	{
		t=1;
		
		for(i=1;i<n;i++)
		
			t=(t+1)*2;	
		
		printf("%d\n",t);   
	}
	return 0;
}