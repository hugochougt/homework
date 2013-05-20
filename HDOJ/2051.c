#include<stdio.h>
int main(void)
{
    int a[11]={0};
    int i,n,b,j;
    while(scanf("%d",&n)!=EOF)
    {
        i=10;
        while(n)
        {
            a[i]=n%2;
            if(!a[i])
                n/=2;
            else
                n=(n-1)/2;
            i--;    
        }    
        for(i=1;a[i]==0;i++)
            ;
        for(j=i;j<=10;j++)
            printf("%d",a[j]);
            printf("\n");
    }
    return 0;
}
