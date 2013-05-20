#include<stdio.h>
int main(void)
{
    int m,i,n,x,min;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        scanf("%d",&x);
        min=x;
        for(i=1;i<n;i++)
        {
            scanf("%d",&x);
            if(x<min)
                min=x;    
        }
        printf("%d\n",m/min);
    }   
    return 0;
}
