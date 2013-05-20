#include "stdio.h"
#define PI 3.1415927

int main(void)
{
    double r,v;
    while(scanf("%lf",&r)!=EOF){
    	v=PI*r*r*r*4.0/3.0;
    	printf("%.3lf\n",v);
    }
    return 0;
}