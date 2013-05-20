#include<stdio.h>

int a[101][101];

int main(void)
{
    int C,N,i,j;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&N);
        for(i=1;i<=N;i++)
            for(j=1;j<=i;j++)
                scanf("%d",&a[i][j]);    
        for(i=N;i>0;i--)
            for(j=1;j<i;j++)
            {
                if(a[i][j]>a[i][j+1])
                    a[i-1][j]+=a[i][j];
                else
                    a[i-1][j]+=a[i][j+1];
                    
            }
        printf("%d\n",a[1][1]);
    }       
    return 0;
}
