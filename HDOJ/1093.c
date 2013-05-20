/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int N,M,x,sum,i,j;
    while((scanf("%d",&N))!=EOF){
    	for(i=0;i<N;i++){
  			scanf("%d",&M);
  			for(j=0,sum=0;j<M;j++){
    			scanf("%d",&x);
    			sum+=x;
  			}
  		printf("%d\n",sum);	
    	}
    }	
}