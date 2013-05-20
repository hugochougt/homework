#include<stdio.h>
int main()
{
    int n,m,i,tag,*p;
    while(scanf("%d%d",&m,&n)!=EOF)
    {
        if(n>=m)
        {
            printf("%d",m);
            for(i=m+1;i<=n;i++)
                printf(" %d",i);
            printf("\n");    
        }
        else{
                p = (int *)calloc(m+1, sizeof(int));
                for(i=1,tag=0;i<=m;i++)
                {
                    if(i-tag<=n)   
                        p[i]=1;
                    else
                        tag=i;;
                }
                if(p[m]==1)
                {    
                    printf("%d\n",m%(n+1));    
                }
                else
                    printf("none\n");
                free(p);
            }
    }
    return 0;
}
