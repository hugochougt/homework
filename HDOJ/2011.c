#include <stdio.h>
#include <math.h>

int main(void)
{
	int n,m,i;
	double sum;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		for(sum=0.0,i=1;i<=m;i++)
			sum+=1.0/i*pow(-1,(i+1));
		printf("%.2lf\n",sum);
	}	
	return 0;
}