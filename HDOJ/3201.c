#include <stdio.h>
#define PI 3.14159
int main(void)
{
    double L;
    while(scanf("%lf",&L)!=EOF)
    {
	     if(0==L)  break;
         printf("%.2lf\n",L*L/PI/2.0);
    }
    return 0;
} 
