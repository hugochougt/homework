#include<stdio.h>
#include<string.h>
int main(void)
{
    char s[10002];
    int i,n,c,l;
    scanf("%d%*c",&n);
    while(n--)
    {
        gets(s);
        l=strlen(s);
        c=1;
        for(i=0,c=1;i<l;i++)
        {
            if(s[i]==s[i+1])
                c++;
            else if(c!=1)
                {
                    printf("%d%c",c,s[i]);
                    c=1;
                    }
            else
                printf("%c",s[i]);
            }
        printf("\n");
    }    
    return 0;
}
