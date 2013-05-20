#include<stdio.h>
int main(void)
{
    double a[21]={0,3,7};
    int i,n,T;
    for(i=3;i<=20;i++)
        a[i]=a[i-1]+a[i-2];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%.0lf\n",a[n]);    
    }    
    return 0;
}
