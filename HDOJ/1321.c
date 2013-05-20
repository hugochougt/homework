#include<stdio.h>
#include<string.h>
int main(void)
{
    int n,i,len,t;
    char s[72];
    scanf("%d%*c",&t);
    while(t--)
    {
        gets(s);
        len=strlen(s);
        for(i=len-1;i>-1;i--)
            putchar(s[i]);
        putchar('\n');    
    }
    return 0;
}
