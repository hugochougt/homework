/* Note:Your choice is C IDE */
#include "stdio.h"
void main()
{
    int N,x,sum,i;
    while((scanf("%d",&N))!=EOF){
    	if(0==N)	break;
    	for(i=0,sum=0;i<N;i++){
    		scanf("%d",&x);
    		sum+=x;
    	}
    	printf("%d\n",sum);
    }
}