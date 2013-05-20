#include<stdio.h>
int main(void)
{
    int a[1003][1003]={0};
    int i,j,k,n;
    while(scanf("%d",&n),n)
    {
         for(i=1;i<=n;i++)
            scanf("%d",&a[i][0]);
         for(i=1;i<=n;i++)
            for(j=i,k=1;j>=0;j--)
            {
                if(a[i][0]>a[i-1][0])
                {
                    a[i][k]+=a[]    
                }
            }   
    }    
}
