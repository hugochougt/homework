#include<stdio.h>
#include<stdlib.h>
int cmp(int *a,int *b)
{
    if(*a==*b)
        return 0;
    else
        return *a-*b;    
}
int main()
{
    int n,i,tag;
    int a[201];
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        qsort(a,n,sizeof(int),cmp);
        if(n<4)
        {
            if(a[1]==a[0])
                printf("%d\n",a[2]);
            else
                printf("%d\n",a[0]);    
        }
        else
        for(i=0,tag=0;i<n-1;i++)
        {
            if(a[i]!=a[i+1])
                if(a[i+1]!=a[i+2])
                {
                    printf("%d\n",a[i+1]);
                    break;    
                }
        }
    }
    return 0;
}
