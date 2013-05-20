#include<stdio.h>
#include<math.h>

double F(double x,double y)
{
    return  6*pow(x,7.0)+8*pow(x,6.0)+7*pow(x,3.0)+5*pow(x,2.0)-y*x; 
}

int main()
{
    double y,ans,lmid,rmid,l,r,lans,rans;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf",&y);
            l=0;
            r=100;
            while(fabs(r-l)>1e-8)
            {
                lmid=(l*2+r)/3;
                rmid=(l+r*2)/3;
                lans=F(lmid,y);
                rans=F(rmid,y);
                if(lans<=rans)
                    r=rmid;
                else
                    l=lmid;
            }
            printf("%.4lf\n",F(r,y));
    }
    return 0;
}
