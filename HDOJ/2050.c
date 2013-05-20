#include<stdio.h>
int main(void)
{
    int C,n,i;
    __int64 a[10001]={1,2};
    for(i=2;i<=10000;i++)
        a[i]=a[i-1]+4*(i-1)+1;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&n);
        printf("%I64d\n",a[n]);
    }
    return 0;   
}
