#include<stdio.h>
int main(void)
{
    char a,b;
    int n,i,j,k,l,m;
    while(scanf("%d %c %c",&n,&a,&b)!=EOF)
    {
        printf(" ");
        for(i=1;i<n-1;i++)
            printf("%c",b);
        printf(" \n");
        for(i=1;i<=(n-1)/2;i++)
        {
            for(j=1;j<=i;j++)
                if(j%2==1)
                    printf("%c",b);
                else
                    printf("%c",a);
            for(j=1;j<=n-2*i;j++)
                if(i%2==1)
                    printf("%c",a);
                else
                    printf("%c",b);
            for(j=i;j>=1;j--)
                if(j%2==1)
                    printf("%c",b);
                else
                    printf("%c",a);
            printf("\n");
        }
        for(i=n/2-1,k=1;i>=1;i++,k++)
        {
            for(j=i;j>=1;j--)
                if(j%2==1)
                    printf("%c",a);
                else
                    printf("%c",b);
            for(j=1;j<=2*k+1;j++)
                if(i%2==0)   
                    printf("%c",b);
                else
                    printf("%c",a);
            for(j=i;j>=1;j--)
                if(j%2==1) 
                    printf("%c",a);
                else
                    printf("%c",b);
            printf("\n");
        }
        printf(" ");
        for(i=1;i<n-1;i++)
            printf("%c",b);
        printf(" \n");
    }        
    return 0;
}
