#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T,n,i,j,k,t;
    int a[1001];
    scanf("%d",&t);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(j=0;j<n-1;j++)
            for(i=0;i<n-1-j;i++)
                if(a[i]>a[i+1])
                {
                    t=a[i];
                    a[i]=a[i+1];
                    a[i+1]=t;   
                }
        for(i=0;i<n;i++)
            printf("%d%c",a[i],i<n-1?' ':'\n');
    }        
    system("pause");
    return 0;
}
