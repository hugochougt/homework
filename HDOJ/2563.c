#include<stdio.h>
int main(void)
{
    double a[21]={0,3,7};
    int C,n,i;
    for(i=3;i<=20;i++)
        a[i]=a[i-2]*3+(a[i-1]-a[i-2])*2;
    scanf("%d",&C);
    while(C--)
    {
        scanf("%d",&n);
        printf("%.0lf\n",a[n]);    
    }
    return 0;
}
