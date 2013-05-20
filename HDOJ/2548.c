#include <stdio.h>

int main(void)
{
    double u,v,w,l,res;
    int t;
    scanf("%d",&t);
    while(t--)
    {
         scanf("%lf%lf%lf%lf",&u,&v,&w,&l);
         res=l/(u+v)*w;
         printf("%.3lf\n",res);          
    }    
    return 0;
}
