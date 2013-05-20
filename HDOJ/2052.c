#include<stdio.h>
int main(void)
{
    int i,j,n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        printf("+");
        for(i=0;i<n;i++)
            printf("-");
        printf("+\n");
        for(i=0;i<m;i++)
        {
            printf("|");
            for(j=0;j<n;j++)
                printf(" ");
            printf("|\n");    
        }
        printf("+");
        for(i=0;i<n;i++)
            printf("-");
        printf("+\n\n");
    }    
    return 0;
}
