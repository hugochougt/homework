#include<stdio.h>
int a[500001];
int main(void)
{
    int i,n,T,j;
    for(i=0;i<=500000;i++)  
        a[i]=1;
    for(i=2;i<250000;i++)
        for(j=i+i;j<=500000;j+=i)
            a[j]+=i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);    
    }
    return 0;
}
