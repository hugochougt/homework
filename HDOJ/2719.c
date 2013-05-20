#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[80];
    int i;
    while(gets(s))
    {
        if(!strcmp("#",s))
            break;
        for(i=0;s[i]!='\0';i++)
            switch(s[i])
            {
                case ' ':printf("%%20");break;
                case '!':printf("%%21");break;
                case '$':printf("%%24");break;
                case '%':printf("%%25");break;
                case '(':printf("%%28");break;
                case ')':printf("%%29");break;
                case '*':printf("%%2a");break;
                default:printf("%c",s[i]);break;    
            }    
        printf("\n");
    }
    return 0;
}
