#include<stdio.h>
void main()
{
    double f[10];
    double max,min,ave,sum=0;
    int i;
    for(i = 0; i<10; i++)
    {
        scanf("%lf",&f[i]);
        sum=sum+f[i];
    }
    max = -1;
    min = 101;
    for(i=0;i<10;i++)
    {
        if(max<f[i])
            max=f[i];
        if(min>f[i])
            min=f[i];
    }
    ave=(sum-min-max)/8;
    printf("%.2lf\n",ave);
    system("pause");
}
