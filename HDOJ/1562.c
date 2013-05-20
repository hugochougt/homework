#include<stdio.h>
int main(void)
{
    int a,b,c,x,i,t,tag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);   
        for(i=1000,tag=0;i<=9999;i++)
        {
            if((i%a==0)&&((i+1)%b==0)&&((i+2)%c==0))
            {
                tag=1;
                goto S;
            }
        }
        S:
        if(tag)   printf("%d\n",i);
        else    printf("Impossible\n");
    }
    return 0;
}
