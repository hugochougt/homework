#include<stdio.h>
int main(void)
{
    double sum[50001]={0.0,1.0},tmp[50001]={0.0,1.0};
    int i,n;
    for(i=2;i<=50000;i++)
    {
        tmp[i]+=tmp[i-1]+1.0/i;
        sum[i]+=sum[i-1]+2*tmp[i]-1;
    }  
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n)    break;
        printf("%.2lf\n",sum[n]);    
    }
    return 0;
}
