#include<stdio.h>

int main(void)
{
    int N,n,i,j;
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&n);
        for(i=0;i<3*n;i++)
            for(j=0;j<n;j++)
            {
                printf("HDU");   
                if(j==n-1)
                    printf("\n");
            }
    }
    return 0;
}
