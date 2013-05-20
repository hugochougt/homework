#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    return *a - *b;    
}

int main()
{
    int a[10005],i,j,k,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i = 0; i < n; i++)
            scanf("%d",a+i);
        if(n==1)
        {
            printf("%d\n",a[0]);
        }
        else if(n==2)
        {
            if(a[0]>a[1])
                printf("%d %d\n",a[0],a[1]);
            else
                printf("%d %d\n",a[1],a[0]);
        }
        else
        {
            qsort(a, n, sizeof(int), cmp);
            printf("%d",a[n-1]);
            for(j=0,k=n-2;j<k;j++,k--)
            {
                printf(" %d %d",a[j],a[k]);
            }
            if(n%2==1)
                printf("\n");
            else
                printf(" %d\n",a[j]);
        }
    }
    return 0;
}
