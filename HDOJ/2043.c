#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char s[51];
    int len,n,dx,xx,tsfh,sz,i,c;
    scanf("%d",&n);
    while(n--)
    {
        dx=xx=tsfh=sz=0;
        scanf("%s",s);
        len=strlen(s);
        if(len<8 || len>16)
        {
            printf("NO\n");
            continue;    
        } 
        for(i=0;i<len;i++)
        {
            if(isdigit(s[i]))
                sz++;
            else if(isupper(s[i]))
                dx++;
            else if(islower(s[i]))
                xx++;
            else if(ispunct(s[i]))
                tsfh++;        
        }   
        c=0;
        if(sz>0)    c++;
        if(dx>0)    c++;
        if(xx>0)    c++;
        if(tsfh>0)    c++;
            
        if(c>2)
            printf("YES\n");
        else
            printf("NO\n");
    }    
    return 0;
}
