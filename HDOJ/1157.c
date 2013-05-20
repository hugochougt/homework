#include<stdio.h>
#include<stdlib.h>

int cmp(const int *a, const int *b)
{
    int v=*a - *b;
    if(!v)
        return 0;
    else
        return v;
}
int main(void)
{
    int N,*p=NULL,i;
    while(scanf("%d",&N)!=EOF)
    {
        p = (int *)calloc(N, sizeof(int));
        for(i=0;i<N;i++)
            scanf("%d",p+i);
        qsort(p, N, sizeof(int), cmp);
        printf("%d\n",*(p+N/2));    
    }    
    return 0;
}
