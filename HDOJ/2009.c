#include <stdio.h>
#include <math.h>
int main(void)
{
	int n,m;
	double sum;
	while(scanf("%d %d",&n,&m)!=EOF){
		sum=n;
		while(--m){
			sum+=sqrt((double)n);
			n=sqrt((double)n);
		}
		printf("%.2lf\n",sum);
	}    
	return 0;
}
