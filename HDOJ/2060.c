#include <stdio.h>
int main(void)
{
	int N,ball,P,O;
	
	scanf("%d",&N);
	
	while(N--)
	{
		scanf("%d%d%d",&ball,&P,&O);
		
		if(ball>6)	P+=8*(ball-6);
		else		P+=0;
		if(ball>6)	P+=27;
		else		P+=ball*(15-ball)/2;
		if(P>=O)	printf("Yes\n");
		else		printf("No\n");
	}    
	return 0;
}