#include<stdio.h>
int a[1000005]={0};
int main(void)
{
    int n,m,i,j,k;  
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&j);
            a[j+500000]=1;  
        }
        for(i=1000004,j=0;j<m;i--)
        {
            if(a[i]==1)
            {
                printf(j>0?" %d":"%d",i-500000);
                j++;    
            }
        }
        printf("\n");
    }  
    return 0;
}
