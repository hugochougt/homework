#include<stdio.h>
int main()
{
    __int64 a[36]={0,1,2};
    int i,n,c=1,j,k;
    for(i=3;i<=35;i++)  
    {
        a[i]=a[i-1]*(4*(i-1)+2)/(i+1);
    }
    while(scanf("%d",&n)!=EOF)
    {
        if(n==-1)   break;
        printf("%d %d %I64d\n",c++,n,a[n]*2);
    } 
    return 0;
}
