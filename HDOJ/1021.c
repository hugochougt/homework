#include<stdio.h>

int main(void)
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%4==2)
            printf("yes\n");
        else
            printf("no\n");
    }    
    return 0;
}
