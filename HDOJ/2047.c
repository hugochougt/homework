#include<stdio.h>
int main(void)
{
    __int64 a[40][2];
    int i,n;
    a[1][0]=1;a[1][1]=2;
    for(i=2;i<40;i++)
    {
        a[i][0]=a[i-1][1];
        a[i][1]=2*(a[i-1][0]+a[i-1][1]);
        }
    while(scanf("%d",&n)!=EOF)    
        printf("%I64d\n",a[n][0]+a[n][1]);
    return 0;
}
