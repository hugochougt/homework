#include<stdio.h>
int main(void)
{
    int n;
    double s,e,A1,cn,sum,i;
    
    while(scanf("%d",&n)!=EOF)
    {
        
        scanf("%lf%lf",&s,&e);    
        for(i=0,sum=0;i<n;i++)
        {
            scanf("%lf",&cn);
            sum+=cn;    
        }
        A1=s+e-2*sum;
        printf("%.2lf\n",A1);
    }    
    return 0;
}
