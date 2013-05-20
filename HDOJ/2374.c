#include<stdio.h>
int main()
{
    int n,i,j;
    //int k;
    __int64 a[53],sum;
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n) break;
        for(i=1;i<=n;i++)
            scanf("%I64d",a+i);
        for(i=n;i>=2;i--)
        {
            for(j=i-1;j>=1;j--)
                a[j]=a[j]+a[i];
            //for(k=1;k<=n;k++)
            //    printf("%I64d ",a[k]);
            //printf("\n");
        }
        sum=0;
        for(i=1;i<=n;i++)
            sum+=a[i];
        printf("%I64d\n",sum);
    }
    return 0;
}
