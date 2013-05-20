#include "stdio.h"

int main(void)
{
	int i,n,x,m;
	
	scanf("%d",&n);
	
	while(n--){
		x=3;
		
		scanf("%d",&m);
		
		for(i=0;i<m;i++)
			x=(x-1)*2;
			
		printf("%d\n",x);
	}    
	return 0;
}