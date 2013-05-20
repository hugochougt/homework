#include<stdio.h>
#include<math.h>
int main(void)
{
    int n,i;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==1||(n%2==0))
            printf("2^? mod 2 = 1\n");
        else{
            i=1;
            S:
            if((int)pow(2,i)%n==1)
                printf("2^%d mod %d = 1\n",i,n);
            else{
                i++;    
                goto S;    
            }
        }    
    }    
    return 0;
}
