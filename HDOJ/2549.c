#include <stdio.h>
#include <string.h>

int main(void)
{
    int t,n,i,len;
    char s[1000];
    scanf("%d",&t);
    while(t--)
    {
         scanf("%s",s);
         scanf("%d",&n);
         len=strlen(s);
         for(i=0;s[i]!='.';i++)
            ;
         if(n+i<len)   
            printf("%c\n",s[i+n]);
         else
            printf("0\n");       
    }
    return 0;
}
