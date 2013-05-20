#include<stdio.h>
int main(void)
{
    double a[51]={0,3,6,6};
    int n,i;
    for(i=4;i<=50;i++)   
         a[i]=a[i-1]+2*a[i-2];
    while(scanf("%d",&n)!=EOF)
        printf("%.0lf\n",a[n]);    
    return 0;
}
