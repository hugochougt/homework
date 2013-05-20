#include<stdio.h>

int main(void)
{
    int M,i;
    double a[51]={0,1,2};
    for(i=3;i<=50;i++)
        a[i]=a[i-1]+a[i-2];
    while(scanf("%d",&M)!=EOF)
    {
        printf("%.0lf\n",a[M]); 
    }    
    return 0;
}
