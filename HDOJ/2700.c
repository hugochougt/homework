#include <stdio.h>
#include <string.h>
int main()
{
    char str[1000];
    int i,count;
    while(gets(str))
    {
        if(!strcmp("#",str))
            break;
        for(i=0,count=0;str[i]!='\0';i++)
            if(str[i]=='1')
                count++;
        i--;
        if(str[i]=='e')
        {
            if(count%2==0)
                str[i]='0';
            else
                str[i]='1';
        }
        else
        {
            if(count%2==1)
                str[i]='0';
            else
                str[i]='1';    
        }
        printf("%s\n",str);
    }
    return 0;
}
