#include<stdio.h>
int main(void)
{
    int n,T,x,i,sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",&x);   
            sum+=x; 
        }    
        sum=sum-n+1;
        printf("%d\n",sum);
    }    
    return 0;
}
