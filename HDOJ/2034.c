#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a,const int *b)
{
    if(*a==*b)
        return 0;
    else
        return *a-*b;
}
int main(void)
{
    int a[101],b[101],i,j,tag,n,m,c;
    
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(0==n&&0==m)  break;
        
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        for(i=0;i<m;i++)
            scanf("%d",b+i);
            
        qsort(a, n, sizeof(int), cmp);
        qsort(b, m, sizeof(int), cmp);
        
        for(i=0,c=0;i<n;i++)
        {
            for(j=0,tag=0;j<m;j++)
            {
                if(a[i]==b[j])
                {
                    tag=1;
                    break;
                } 
            }
            if(0==tag)
            {
                printf("%d ",a[i]);
                c=1;
            }
        }
        if(0==c)
            printf("NULL\n");
        else
            printf("\n");
    }
    return 0;
}
