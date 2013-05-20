#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(void)
{
    int a[100],b[100];
    int n,i,j,t;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i);   
        for(i=0;i<n-1;i++)
            for(j=0;j<n-1-i;j++)
                if(abs(a[j])<abs(a[j+1]))
                {
                    t=a[j];
                    a[j]=a[j+1];
                    a[j+1]=t; 
                }
        for(i=0;i<n;i++)
            printf("%d%c",a[i],i<n-1?' ':'\n');
    } 
    return 0;   
}
