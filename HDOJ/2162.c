#include<stdio.h>
int main(void)
{
    int sum,n,x,i,c=0;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<=0)    break;
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&x);
            sum+=x;    
        }    
        c++;
        printf("Sum of #%d is %d\n",c,sum);
    }    
    return 0;
}
