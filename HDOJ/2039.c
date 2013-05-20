#include "stdio.h"

int main(void)
{
	int i,N,A,B,C;
	while(scanf("%d",&N)!=EOF)
		for(i=0;i<N;i++){
			scanf("%d %d %d",&A,&B,&C);
			if((A<B+C)&&(B<A+C)&&(C<A+B))
				printf("YES\n");
			else
				printf("NO\n");
		}    
		return 0;
}