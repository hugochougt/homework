#include<stdio.h>

int main(void)
{
    int x,y,n,m,i,t;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n>m)
        {t=n;n=m;m=t;}
        x=y=0;
        for(i=n;i<=m;i++)
            if(i%2==0)
                x+=i*i;
            else
                y+=i*i*i;
        printf("%d %d\n",x,y);
    }    
    return 0;
}
