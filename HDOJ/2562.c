#include <stdio.h>

int main(void)
{
    char s[51],t;
    int C,i,j;
    scanf("%d",&C);
    while(C--)
    {
         scanf("%s",s);
         for(i=0;s[i]!='\0';i+=2)
         {
             t=s[i];
             s[i]=s[i+1];
             s[i+1]=t;                    
         }          
         printf("%s\n",s);
    }    
    return 0;
}
