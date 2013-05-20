#include "stdio.h"

int main(void)
{
	int T;
	unsigned A,B;
	scanf("%d",&T);
	while(T--){
		scanf("%u%u",&A,&B);
		if(B!=0&&0==A%B)
			printf("YES\n");
		else
			printf("NO\n");
	}    
	return 0;
}