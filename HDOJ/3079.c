#include<stdio.h>

int main(void)
{
    char s[51];
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",s);
        for(i=0;s[i]!='\0';i++)
            if((s[i]>=65) && (s[i]<=90))
                s[i]+=32;
        for(i=0;s[i]!='\0';i++)
        {
            switch(s[i]){
                case 'a':s[i]-=32;break;
                case 'e':s[i]-=32;break;
                case 'i':s[i]-=32;break;
                case 'o':s[i]-=32;break;
                case 'u':s[i]-=32;break;
                default:break;
                }    
        }    
        printf("%s\n",s);
    }    
    return 0;
}
