#include "stdio.h"
int main(void)
{
	float c,sum;
	int i;
	
	while(scanf("%f",&c)!=EOF){
		if(0==c)	break;
		sum=0;
		for(i=2;sum<c;i++){
			sum+=1.0/i;
		}
		printf("%d card(s)\n",i-2);
	}    
	return 0;
}