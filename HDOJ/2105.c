#include<stdio.h>
int main(void)
{
    int t,i;
    double x,y,sumx,sumy;
    scanf("%d",&t);
    while(t--)
    {
         for(i=0,sumx=sumy=0.0;i<3;i++)
         {
            scanf("%lf%lf",&x,&y);
            sumx+=x;
            sumy+=y;
        }   
        printf("%.1lf %.1lf\n",sumx/=3,sumy/=3);
    }    
    return 0;
}
