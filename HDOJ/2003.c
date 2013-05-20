#include "stdio.h"
int main(void)
{
    double n;
    while(scanf("%lf",&n)!=EOF)
    	printf("%.2lf\n",n>=0?n:-n);
	return 0;
}