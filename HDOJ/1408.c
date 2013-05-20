#include<stdio.h>
int main(void)
{
    int c,i;
    double V,D;
    while(scanf("%lf%lf",&V,&D)!=EOF)
    {
        for(i=1,c=0;V>0;i++,c++)
        {
            V-=i*D;
            c+=i;
        }
        printf("%d\n",c-1);
    }    
    return 0;
}
