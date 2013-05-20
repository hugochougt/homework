#include<stdio.h>
struct pp
{
    int x;
    int y;
    }p[101];
int main(void)
{
    int n,sum,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n) break;
        scanf("%d%d",&p[0].x,&p[0].y);
        for(i=1,sum=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            j=i-1;
            sum+=p[j].x*p[i].y-p[i].x*p[j].y;
        }
        sum+=p[n-1].x*p[0].y-p[n-1].y*p[0].x;
        printf("%.1lf\n",sum*0.5);
    }    
    return 0;
}
