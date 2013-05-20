#include<stdio.h>
int main(void)
{
    int i,T,n;
    while(scanf("%d",&T)!=EOF)
    {
        for(i=0;i<T;i++)
        {
            scanf("%d",&n);    
            printf("%c",n);
        }    
    }    
    return 0;
}
