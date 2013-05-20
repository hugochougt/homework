#include "stdio.h"

int main(void)
{
	int V[3],n,i,C,j,sum;
	while(scanf("%d",&C)!=EOF){
		for(i=0;i<C;i++){
			scanf("%d",&n);
			V[0]=n/2;
			V[1]=(n-V[0])*2/3;
			V[2]=n-V[0]-V[1];
			sum=0;
			for(j=0;j<3;j++){
				if(0==V[j]%10)
					sum+=(V[j]/10);
				else
					sum+=(V[j]/10+1);
			}
			printf("%d\n",sum);
			}
	}  
	return 0;
}
