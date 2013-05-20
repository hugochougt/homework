#include<stdio.h>

int main(void)
{
    int T,a,b,c,d,m,n,t1,t2,t;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        n=b*d;
        m=a*d+b*c;
        t1=m;
        t2=n;
        if(t1<t2)
            {t=t1;t1=t2;t2=t;}
        while(t2)
        {
            t=t1%t2;
            t1=t2;
            t2=t; 
        }
        printf("%d %d\n",m/t1,n/t1);   
    }    
    return 0;
}
