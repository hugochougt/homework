#include<stdio.h>
int main(void)
{
    double s,sum,GPA,x,x_sum;
    int N,d;    
    while(scanf("%d",&N)!=EOF)
    {
        sum=0.0;
        x_sum=0;
        while(N--)
        {
            scanf("%lf%lf",&x,&s);
            
            x_sum+=x;
            
            if(s==-1)
                continue;
            
            if(s>=0 && s<60)    d=0;
            else if(s<70)   d=1;
            else if(s<80)   d=2;
            else if(s<90)   d=3;
            else if(s<=100) d=4;
            
            sum+=x*d;    
        }  
        if(sum==0)
            printf("-1\n");
        else{
            GPA=sum/x_sum;
            printf("%.2lf\n",GPA);
        }
    }
    return 0;
}
