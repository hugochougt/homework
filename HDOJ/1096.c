#include "stdio.h"
int main(void)
{
    int N,M,x,sum,i,j;
    scanf("%d",&N);
    while(N--)
    {
  		scanf("%d",&M);
  		sum=0;
  		for(j=0;j<M;j++)
        {
   		   scanf("%d",&x);
           sum+=x;
  		}
    	printf("%d\n",sum);	
  		if(N>=1)	printf("\n");
    }
    return 0;
}
