#include<stdio.h>

int gcd(int m, int n)
{
    int r,t;
    
    if(m<n)
    {
        t=m;
        m=n;
        n=t;
    }
    
    while(n != 0)
    {
        r = m % n;
        m = n;
        n = r;    
    }    
    return m;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;    
}

int main(void)
{
    int N,x,res;
    
    while(scanf("%d",&N) != EOF)
    {
        res = 1;
        while(N--)
        {
            scanf("%d",&x);
            res = lcm(res,x);    
        }
        printf("%d\n",res);
    }
    
    return 0; 
} 
