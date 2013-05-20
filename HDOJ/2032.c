#include<stdio.h>
int main(void)
{
    int a[31][31];
    int j,i,n,tag=0;
    for(i=1;i<=30;i++)
        a[i][1]=1;
    for(i=2,j=2;i<=30;i++,j++)
        a[i][j]=1;    
    for(i=3;i<=30;i++)
        for(j=2;j<i;j++)
            a[i][j]=a[i-1][j-1]+a[i-1][j];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=i;j++)
                printf("%d%c",a[i][j],j==i?'\n':' ');    
        }    
         printf("\n"); 
    }    
    return 0;
}
