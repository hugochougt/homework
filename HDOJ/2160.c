#include<stdio.h>
int main(void)
{
    int a[21]={0,1,2,3},i,b[21]={0,0,0,1},n,t;
    for(i=4;i<20;i++)
    {   a[i]=a[i-1]*2-b[i-1];
        b[i]=a[i-2];
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        printf("%d\n",a[n]);  
    }
    return 0;
}
