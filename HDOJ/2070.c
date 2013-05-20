#include<stdio.h>
int main(void)
{
    __int64 a[51]={0,1};
    int i,n;    
    for(i=2;i<=50;i++)
        a[i]=a[i-2]+a[i-1];
    while(scanf("%d",&n) && n!=-1)
        printf("%I64d\n",a[n]);   
    return 0; 
}
