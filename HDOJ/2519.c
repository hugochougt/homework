#include<stdio.h>

int main(void)
{
    int t,i,n,m;
    double a[31]={0,1};
    for(i=2;i<31;i++)
        a[i]=a[i-1]*i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m==0)
            printf("1\n");
        else if(m==n)
            printf("1\n");
        else if(m>n) 
            printf("0\n");
        else  
            printf("%.0lf\n",a[n]/a[m]/a[n-m]);
    }
    return 0;
}
