#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    int v=*a-*b;
    if(!v)
        return 0;
    else
        return v;    
}
int main(void)
{
    int a[102],i,n,sum;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)    break;
        for(i=0;i<n;i++)
            scanf("%d",a+i);
                
        qsort(a, n, sizeof(int), cmp);

        n=(n/2+1);
        for(i=0,sum=0;i<n;i++)
            sum+=(a[i]/2+1);
        printf("%d\n",sum);
    }    
    return 0;
}
