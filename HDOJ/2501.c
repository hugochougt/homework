#include<stdio.h>

int main(void)
{
    int T,i,n;
    double a[31]={0,1,3};
    
    for(i=3;i<=30;i++)
        a[i]=a[i-1]+2*a[i-2];
        
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%.0lf\n",a[n]);    
    }
    return 0;
}
