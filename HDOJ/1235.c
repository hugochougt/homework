#include "stdio.h"
int main(void)
{
	int N,T,i,count,score[1000];
	while(scanf("%d",&N)!=EOF){
		if(0==N)	break;
		count=0;
		for(i=0;i<N;i++)
			scanf("%d",&score[i]);
		scanf("%d",&T);
		for(i=0;i<N;i++)
			if(T==score[i])
				count++;
		printf("%d\n",count);
	}    
	return 0;
}