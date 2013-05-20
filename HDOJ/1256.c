#include<stdio.h>
int main(void)
{
    char c;
    int n,i,t,h,tag=0;
    scanf("%d%*c",&t);
    while(t--)
    {
        scanf("%c%d%*c",&c,&n);
        if(!tag)
            tag=1;
        else
            printf("\n");
        if(n%2==1)  n++;
        h=n/2;
        for(i=1;i<=n;i++)
            if(i==1 || i==h || i==n)
                printf("  %c%c\n",c,c);
            else
                printf("%c%c  %c%c\n",c,c,c,c);
    }
    return 0;
}
