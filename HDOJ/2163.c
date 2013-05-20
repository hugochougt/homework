#include<stdio.h>
#include<string.h>
int main(void)
{
    int i,c=0,len,j,tag;
    char s[54];
    while(gets(s))
    {
        if(!strcmp("STOP",s))
            break;
        if(1==strlen(s))
            printf("#%d: YES\n",++c);
        else{
            len = strlen(s);
            tag=1;
            for(i=0,j=len-1;i<j;i++,j--)
                if(s[i]!=s[j])
                {
                    tag=0;
                    break;
                }
            if(tag)
                printf("#%d: YES\n",++c);
            else
                printf("#%d: NO\n",++c);
            }    
    }    
    return 0;
}
