#include <stdio.h>
#include <math.h>

int main(void)
{
	double n,m,x,y,a,b;
	while(scanf("%lf %lf %lf %lf",&n,&m,&x,&y)!=EOF){
		a=(x-n)*(x-n);
		b=(y-m)*(y-m);
		printf("%.2lf\n",sqrt(a+b));
	}	
	return 0;
}