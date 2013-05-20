#include <stdio.h>
int main(void)
{
	int N,ball,P,O,i,sum,j,red;
	
	scanf("%d",&N);
	
	while(N--)
	{
		scanf("%d",&ball,&P,&O);
		
		if(ball<=6)
			for(sum=0,i=0,j=7;i<ball;i++,j--)
				sum+=j;
		else{
				red=ball-6;
				sum=red+7*red+27;
		}
		
		if(sum>=O-P)	printf("Yes\n");
		else			printf("No\n");
	}    
	return 0;
}