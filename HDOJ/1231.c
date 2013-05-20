#include<stdio.h>
int main()
{
    int MaxSum,ThisSum,sp,ep,i,tag,n,tmp;
    int a[10100];
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n) break;
        MaxSum=-11111111;
        ThisSum=0;
        tmp=1;
        tag=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            if(a[i]>=0) tag=1;
            ThisSum+=a[i];
            if(ThisSum>MaxSum)
            {
                MaxSum=ThisSum;
                sp=tmp;
                ep=i;
            }
            if(ThisSum<0)
            {
                tmp=i+1;
                ThisSum=0;    
            }
        }
        if(tag)
            printf("%d %d %d\n",MaxSum,a[sp],a[ep]);
        else
            printf("0 %d %d\n",a[1],a[n]);
    }
    return 0;
}
