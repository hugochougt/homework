#include<stdio.h>
#include<math.h>
int main()
{
    int T,M,N,x,count,i,cs,tag;
    double sum;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&M,&N);
        count =0;
        sum=0;
        cs=0;
        tag=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&x);
            if(x)  tag=1;
            if(tag || x || count>M)
            {
                cs++;
                count++;
            }
            else
                count++;
        }
        //printf("%d\n",cs);
        for(i=0;i<cs;i++)
            sum+=pow(2.0,(double)i);
        if((int)sum)
            printf("%.lf00000 RMB\n",sum);
        else
            printf("0 RMB\n");
    }
    return 0;
}
