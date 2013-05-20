#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    if(*(a)==*(b))
        return 0;
    else
        return *a-*b;    
}
int main(void)
{
    int t,n,i,a[11];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        qsort(a, n, sizeof(int), cmp);
        printf("%d\n",a[1]);
    }  
    return 0; 
}
