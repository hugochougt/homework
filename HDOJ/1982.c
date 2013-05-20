#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char s[10001];
    int t,i,j,c;
    scanf("%d%*c",&t);
    while(t--)
    {
        gets(s);
        for(i=0;;i++)
        {
            if(s[i]=='#')
            {
                c=0;
                j=i-1;
                if(j>=0 && isdigit(s[j]))
                {        
                    c+=s[j]-'0';
                    j--;
                    if(j>=0 && isdigit(s[j]))
                    c+=(s[j]-'0')*10;
                printf("%c",c+64);
                }
                
                printf(" ");
            }
            else if(s[i]=='-')
                {
                    c=0;
                    j=i-1;
                    if(j>=0 && isdigit(s[j]))
                    {
                        c+=s[j]-'0';
                        j--;
                        if(j>=0 && isdigit(s[j]))
                        c+=(s[j]-'0')*10;
                    printf("%c",c+64);
                    }
                    
                }
            else if(s[i]=='\0')
                {
                    c=0;
                    j=i-1;
                    if(j>=0 && isdigit(s[j]))
                    {
                        c+=s[j]-'0';
                        j--;
                        if(isdigit(s[j]))
                        c+=(s[j]-'0')*10;
                         printf("%c",c+64);
                    }
                    break;
                }
        }
        printf("\n");
    }
    return 0;
}
