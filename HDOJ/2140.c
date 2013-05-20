#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,len;
    char s[10001];
    while(gets(s))
    {
        len = strlen(s);
        for(i=0;i<len;i++)
            switch(s[i])
            {
                case'b':printf(" ");break; 
                case'q':printf(",");break;
                case't':printf("!");break;
                case'm':printf("l");break;
                case'i':printf("e");break;
                case'c':printf("a");break;
                case'a':printf("c");break;
                case'e':printf("i");break;
                case'l':printf("m");break;
                default:printf("%c",s[i]);break;   
            }    
        printf("\n");
    }    
    return 0;
}
