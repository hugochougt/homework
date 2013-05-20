#include <stdio.h>

int main(void)
{
	int A,B,N,i;
	while(scanf("%d",&N)!=EOF){
		for(i=0;i<N;i++){
			scanf("%d %d",&A,&B);
			printf("%d\n",(A+B)%100);
		}
	}
	return 0;
}