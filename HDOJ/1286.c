#include<stdio.h>
int main(void)
{
    int a[32769],i,j,n,cn,c;

    scanf("%d",&cn);
    while(cn--)
    {
        scanf("%d",&n);
        memset(a, 0, sizeof(a));
        for(i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                for(j=i;j<=n;j+=i)
                    a[j]=1;    
            }    
        }
        for(i=1,c=0;i<=n;i++)
            if(0==a[i])
                c++;
        printf("%d\n",c);    
    }    
    return 0;
}
