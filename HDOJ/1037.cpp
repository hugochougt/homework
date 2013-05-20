#include<stdio.h>
int main(void)
{
    const double H = 168.0;
    double a[3];
    int i,tag[3],c;
    while(scanf("%lf%lf%lf",&a[0],&a[1],&a[2])!=EOF)
    {
        for(i=0,c=0;i<3;i++)
        {
            tag[i]=0;
            if(a[i]>H)
            {
                tag[i]++;
                c++;
            }
        }
        if(0==c)
            printf("NO CRASH\n");
        else{
            printf("CRASH ");
            for(i=0;i<3;i++)
               if(tag[i])
                    printf("%lf%c",a[i],c-->0?' ':'\n'); 
            }
    }
    return 0;
}
