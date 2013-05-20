#include<stdio.h>
int main(void)
{
    int a[31]={0,1};
    int n,i,t;
    for(i=2;i<=30;i++)
        a[i]=a[i-1]*2+1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);    
    }    
    return 0;
}
