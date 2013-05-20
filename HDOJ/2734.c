#include<stdio.h>
#include<string.h>
int main()
{
    char str[260];
    int i,sum,len;
    while(gets(&str[1]))
    {
        if(!strcmp("#",&str[1]))
            break;
            sum=0;
        for(i=1;str[i];i++)
        {
            if(str[i]!=' ')
                sum+=i*(str[i]-'@');
        }
        printf("%d\n",sum);
    }
    return 0;
}
