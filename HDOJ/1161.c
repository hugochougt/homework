#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char s[1020];
    int i;
    while(gets(s))
    {
          for(i=0;s[i] != '\0';i++)
            if(isupper(s[i]))
                s[i]+=32;
          printf("%s\n",s);  
    }    
    return 0;
}
