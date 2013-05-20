#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main(void)
{
    int i,j,c,len;
    char str[81],word[6];
    while(gets(word))
    {
        if(0==strcmp("#",word))
            break;
        gets(str);
        
        for(i=0;word[i]!='\0';i++)
        {
            for(j=0,c=0;str[j]!='\0';j++)
                if(word[i]==str[j])
                    c++;
            printf("%c %d\n",word[i],c);
        }
    }
    return 0;
}
