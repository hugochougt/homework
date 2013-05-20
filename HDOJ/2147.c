#include<stdio.h>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if((0==n)&&(0==m))  break;
        if((n%2==1)&&(m%2==1))
            printf("What a pity!\n");
        else
            printf("Wonderful!\n"); 
    }
    return 0;
}
