#include <stdio.h>

int main(void)
{
    char c;
    int n,i,j,tag=0;
    while(scanf("%c",&c)!=EOF && c!='@')
    {
        scanf("%d%*c",&n);
        if(!tag)
            tag = 1;
        else
            printf("\n");
        if(1==n)    printf("%c\n",c);
        else if(n==2)   printf(" %c\n%c%c%c\n",c,c,c,c);
        else
        {
            for(i=1;i<=n-1;i++)
            {
                printf(" ");
                for(j=1;j<=n-i-1;j++)
                    printf(" ");
                for(j=1;j<=2*i-1;j++)
                        if(j==1||j==2*i-1)
                            printf("%c",c);
                        else
                            printf(" ");
                        printf("\n");
            }  
            for(i=1;i<=2*n-1;i++)
                printf("%c",c);
            printf("\n");    
        }
    }    
    return 0;
}
