#include<stdio.h>
#include<stdlib.h>
int cmp(int *a, int *b)
{
    return *a-*b;
}
int main()
{
    int n,m,i,s,t;
    int a[50];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        qsort(a, n, sizeof(int), cmp);
        s=(100-a[m-1])*(100-a[m-1]);
        for(i=m-2;i>-1;i--)
            s+=(a[i+1]-a[i])*(a[i+1]-a[i]);
        printf("%d\n",s);
    }
    return 0;
}
