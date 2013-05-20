#include<stdio.h>
int main(void)
{
    int n,m,t,N,M;
    int sum(int a);
    scanf("%d",&t);
    while(t--)    
    {
        scanf("%d%d",&n,&m);
        if(n!=1)
            N=sum(n);
        else N=1;
        if(m!=1)
            M=sum(m);
        else M=1;
        printf("%d\n",M*N);    
    }
    return 0;
}

int sum(int a)
{
    return (1+a)*a/2;    
}
