#include<stdio.h>
int main(void)
{
    int a[21],i,n;
    a[2]=1;
    for(i=3;i<21;i++)
        a[i]=i*a[i-1];
    while(scanf("%d",&n)!=EOF)
    {
        printf("%d\n",a[n]);    
    }    
    return 0;
}
