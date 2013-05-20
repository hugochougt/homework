#include<stdio.h>

int main(void)
{
    __int64 n,sum;
    while(scanf("%I64d",&n),n)
    {
        START:
        sum=0;
        if(n>9)
        {
            sum=0;
            while(n>0)
            {
                sum+=n%10;
                n/=10;
            }  
            n=sum;
            if(sum>9)
                goto START;
            else
                goto END;
        }
        else
            sum=n;
        END:
            printf("%d\n",sum);
    }    
    return 0;
}
