#include<stdio.h>

int Isprime(int n)
{
    int i,prime=1;
    for(i=2;i<=(int)sqrt(n);i++)
        if(n%i==0)
        {
            prime=0;
            break;    
        }    
    if(prime)
        return 1;
    else
        return 0;   
}
int main(void)
{
    int i,m,n,res,c;
    int a[90]={0};
    for(i=-39;i<=50;i++)
    {
        res=i*i+i+41;
        if(Isprime(res))
            a[i+39]=1;       
    }
    while(scanf("%d%d",&m,&n),n||m)
    {
        for(i=m,c=0;i<=n;i++)
            if(a[i])
                c++;
        if(c==(n-m+1))
            printf("OK\n");
        else
            printf("Sorry\n");
    }    
    return 0;
}
