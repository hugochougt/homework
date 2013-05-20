#include "stdio.h"
int main(void)
{
	int A,B;
	while(scanf("%d %d",&A,&B)!=EOF){
		if(0==(A+B)%86)
			printf("yes\n");
		else
			printf("no\n");
	}    
	return 0;
}