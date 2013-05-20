#include<stdio.h>
int main(void)
{
    char str[101],max;
    int i;
    while(gets(str))
    {
        max=str[0];
        for(i=1;str[i]!='\0';i++)
            if(str[i]>max)
                max=str[i];
        for(i=1;str[i]!='\0';i++)
            if(str[i]==max)
                printf("%c(max)",str[i]);
            else
                printf("%c",str[i]);
        printf("\n");
    }   
    return 0;
}
