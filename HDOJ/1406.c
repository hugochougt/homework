#include<stdio.h>
int main(void)
{
    int a[10001],n,j,i,m,T,t,c=0,b[10001]={0};
    for(i=0;i<=10000;i++)
        a[i]=1;
    for(i=2;i<=10000;i++)
        for(j=i+i;j<=10000;j+=i)
            a[j]+=i;
    for(i=2;i<=10000;i++)
    {
        
        if(i==a[i])
            c+=1;  
        b[i]+=c;      
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(n>m)
        {t=n;n=m;m=t;}
        printf("%d\n",b[m]-b[n]);    
    }
    return 0;
}
