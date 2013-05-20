#include<stdio.h>
#include<math.h>
#define Pi 3.14159
int main(void)
{
    int r;
    double r1,r2,R,s;
    while(scanf("%d",&r)!=EOF)
    {
        if(r==0)    break; 
        R=1.0*r;
        s=Pi*R*R;
        s/=3;
        r2=sqrt(s/Pi); 
        r1=sqrt(2*s/Pi);
        printf("%.3lf %.3lf\n",r2,r1); 
    }
    return 0;
}
