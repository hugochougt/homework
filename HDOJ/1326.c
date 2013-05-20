#include<stdio.h>
int main(void)
{
    int a[51];
    int i,n,sum,ave,c,ks=1;
    while(scanf("%d",&n),n)
    {
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%d",a+i);
            sum+=a[i];
            }    
        ave=sum/n;
        for(i=0,c=0;i<n;i++)
            if(a[i]>ave)
                c+=(a[i]-ave);
        printf("Set #%d\n",ks);
        printf("The minimum number of moves is %d.\n\n",c);
        ks++;
    }    
    return 0;
}
