#include<stdio.h>
int main(void)
{
    double a[56]={0,1,2,3};
    int n,i;
    for(i=4;i<55;i++)   
         a[i]=a[i-1]+a[i-3];
    while(scanf("%d",&n),n)
    {
        printf("%.0lf\n",a[n]);    
    }
    return 0;
}
