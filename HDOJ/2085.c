#include<stdio.h>
int main(void)
{
    __int64 h[34]={1},l[34]={0};
    int i,n;
    for(i=1;i<=33;i++)
    {
        h[i]=3*h[i-1]+2*l[i-1];    
        l[i]=l[i-1]+h[i-1];
    }    
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)   break;
        printf("%I64d, %I64d\n",h[n],l[n]);    
    }
    return 0;
}
