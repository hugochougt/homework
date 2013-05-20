#include<stdio.h>
int main(void)
{
    int t,i,c=0;
    char s[51];
    scanf("%d%*c",&t);
    while(t--)
    {
        gets(s);
        for(i=0;s[i]!='\0';i++)
            if(s[i]=='Z')
                s[i]='A';
            else
                s[i]++;
        printf("String #%d\n%s\n",++c,s);
    }    
    return 0;
}
