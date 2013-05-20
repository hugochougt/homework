#include <stdio.h>
#include <stdlib.h>
int const N = 10;
int cmp(int *a,int *b);
int main()
{
    int i,a[N],n,c;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&c);
        for(i=0;i<N;i++)
            scanf("%d",a+i);
        qsort(a,N,sizeof(int),cmp);
        printf("%d %d\n",c,a[2]);    
    }
    return 0;
}

int cmp(int *a,int *b)
{
    return *b-*a;    
}
