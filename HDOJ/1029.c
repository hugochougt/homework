#include<stdio.h>
#include<stdlib.h>
int p[1000000];
int cmp(const int *a, const int *b)
{
    if(*a==*b)
        return 0;
    else
        return *a-*b;
}
int main()
{
    int n,i,c,tmp;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",p+i);
        qsort(p, n, sizeof(int), cmp);
        tmp=(n+1)/2;
        for(i=1,c=1;i<n;i++)
        {
            if(p[i]==p[i-1])
                c++;
            else
                c=1;
            if(c>=tmp)
            {
                printf("%d\n",p[i]);
                break;    
            }
        }
    }
    return 0;
}
