#include<stdio.h>
#include<math.h>
int main(void)
{
    double x1,x2,x3,y1,y2,y3;
    double a,b,c,s;
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&x2,&y2,&x3,&y3);
        a=((y1-y2)*(x1-x3)-(y1-y3)*(x1-x2))/((x1-x2)*(x1-x3)*(x2-x3));
        b=-x1*2*a;
        c=y1-a*x1*x1-b*x1;
        s=a/3*(x3*x3*x3-x2*x2*x2)+b/2*(x3*x3-x2*x2)+c*(x3-x2)-0.5*(x3-x2)*(y2+y3);
        printf("%.2lf\n",s);
    }    
    return 0;
}
