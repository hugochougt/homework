#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    return *a-*b;    
}
int main()
{
    int a[10010],b[10010];
    int n,m,i,last,j,k;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        a[n]=2147483647;
        for(i=0;i<m;i++)
            scanf("%d",b+i);
        b[m]=2147483647;
        qsort(a,n,sizeof(int),cmp);
        qsort(b,m,sizeof(int),cmp);
        last=n+m;
        i=j=k=0;
        if(a[j]<b[k])
        {
            printf("%d",a[j]);
            j++;
            i++;
        }
        else if(a[j]==b[k])
            {
                printf("%d",a[j]);
                j++;
                k++;
                i++;
                last--;
            }
        else
        {
            printf("%d",b[k]);
            k++;
            i++;
        }
        for(;i<last;i++)
        {
            if(a[j]<b[k])
            {
                printf(" %d",a[j]);
                j++;
            }
            else if(a[j]==b[k])
                {
                    printf(" %d",a[j]);
                    j++;
                    k++;
                    i++;
                }
            else
            {
                printf(" %d",b[k]);
                k++;
            }
        }
        printf("\n");
    }
    return 0;
}
