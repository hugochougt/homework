#include "stdio.h"
#include <math.h>
int main(void)
{
	double x1,y1,x2,y2,jiao,d,l;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		d=fabs(x1*x2-y1*y2)/sqrt(x1*x1+y1*y1);
		l=hypot(x2,y2);
		jiao=asin(d/l);
		printf("%.2lf\n",jiao);
	}    
	return 0;
}