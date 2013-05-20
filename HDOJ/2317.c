#include<stdio.h>
int main(void)
{
    int T,r,e,c;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&r,&e,&c);
        e-=c;
        if(r>e)
            printf("do not advertise\n");
        else if(r<e)  
            printf("advertise\n");
        else
            printf("does not matter\n");
    }    
    return 0;
}
