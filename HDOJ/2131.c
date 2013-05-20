#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(void)
{
    char c,s[201];
    int i,n,count;
    float p;
    while(scanf("%c%*c",&c)!=EOF)
    {
        gets(s);
        if(isupper(c))
            c+=32;
        n=strlen(s);
        for(i=0,count=0;i<n;i++)
        {
            if(isupper(s[i]))
                s[i]+=32;
            if(s[i]==c)
                count++;
        }
        p=count*1.0/n;
        printf("%.5f\n",p);   
    }   
    return 0; 
}
