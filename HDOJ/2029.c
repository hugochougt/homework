#include<stdio.h>
#include<math.h>
int main()
{
    double n,m,d,res;
    while(scanf("%lf%lf",&n,&m)!=EOF)
    {
        if((0==n)&&(0==m))
            break;
        d = sqrt(n*n-4*m);
        if(d<0)printf("No\n");
        else{
            if(d-(int)d>0.000001) printf("No\n");
            else
            {
                res = (n+d)*0.5;
                if(res-(int)res>0.000001)
                    printf("No\n");
                else
                    printf("Yes\n");
            }
        }
    }
    return 0;
}
