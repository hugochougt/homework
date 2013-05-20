#include<stdio.h>
#define v0 1
#define a 2
int main(void)
{
    int n,t;
    __int64 s;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&t);
        s=t*t;
        s%=10000;
        printf("%I64d\n",s);
    }    
    return 0;
}
