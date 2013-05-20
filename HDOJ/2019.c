#include<stdio.h>
int main(void)
{
    int a[103],i,n,m,j,tag;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        for(i=0;a[i]<m;i++)
            ;
        tag=i-1;
        for(j=n;j>tag;j--)
            a[j]=a[j-1];
        a[i]=m;
        for(i=0;i<=n;i++)
            printf("%d%c",a[i],i<n?' ':'\n');       
    }    
    return 0;
}
