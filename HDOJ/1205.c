#include<stdio.h>

int main(void)
{
    int T,n,i,max,a;
    long long sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0,sum=0,max=0;i<n;i++)
        {
            scanf("%d",&a);    
            sum+=a;
            if(max<a)
                max=a;
        }
        sum-=max;
        if((max-sum)>1)
            printf("no\n");
        else
            printf("yes\n");
    }
    return 0;
}
