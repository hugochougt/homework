#include<stdio.h>
int main(void)
{
    int n,u,d,i,count;
    while(scanf("%d %d %d",&n,&u,&d)!=EOF,n)
    {
        count=0;
        while(u<n)
        {
            n-=u;
            count++;
            n+=d;   
            count++; 
        }
        count++;
        printf("%d\n",count);
    }    
    return 0;
}
