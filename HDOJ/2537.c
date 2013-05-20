#include<stdio.h>

int main(void)
{
    char s[30];
    int y,r,i,n,tmp;
    while(scanf("%d%*c",&n)!=EOF)
    {
        if(0==n) break;
        gets(s);
        y=r=0;
        tmp=n-1;
        for(i=0;i<tmp;i++)
        {
            
            if(s[i]=='Y')
                y++;
            else 
                r++;
        }
        if(s[n-1]=='B')  //红打进最后一球 
        {
            if(r<7)
                printf("Yellow\n");
            else
                printf("Red\n");
        }
        else
        {
            if(y<7)
                printf("Red\n");
            else
                printf("Yellow\n");
        }
    }
    return 0;
}
