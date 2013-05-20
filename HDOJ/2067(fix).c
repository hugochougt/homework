#include<stdio.h>
int main()
{
    __int64 a[36][36]={0};
    int i,c=1,j,n;
    for(i=1;i<36;i++)
    {
        a[i][0]=1;
    }
    for(i=1;i<36;i++)
    {
        for(j=1;j<=i;j++)
            a[i][j]+=a[i-1][j]+a[i][j-1];    
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)   break;
        printf("%d %d %I64d\n",c++,n,a[n][n]*2);
    }
    return 0;
}
