#include<stdio.h>
#include<string.h>
char s[10000];
int main(void)
{
    int n,sum,i;
    while(scanf("%s",s)!=EOF)
    {
        for(i=0,n=0;i<strlen(s);i++)
            n+=s[i]-'0';
        if(n==0)  break;
        else 
        {
            START:
            sum=0;
            if(n>9)
            {
                sum=0;
                while(n>0)
                {
                    sum+=n%10;
                    n/=10;
                }  
                n=sum;
                if(sum>9)
                    goto START;
                else
                    goto END;
            }
            else
                sum=n;
            END:
                printf("%d\n",sum);    
        }   
    }  
    return 0;  
}
