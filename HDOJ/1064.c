#include<stdio.h>
int main(void)
{
    double x,sum,i;
    for(sum=0.0,i=0;i<12;i++)
    {
        scanf("%lf",&x);
        sum+=x;
    }
    sum/=12;
    printf("$%.2lf\n",sum);      
    return 0;
}
