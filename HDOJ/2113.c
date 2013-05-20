#include<stdio.h>

int main(void)
{
    char s[100];
    int a[100],i,len,sum,j=0;
    while(scanf("%s",s)!=EOF)
    {
        for(i=0;s[i]!='\0';i++) 
            a[i]=s[i]-'0';
        for(i=0,sum=0;s[i]!='\0';i++)
            if(a[i]%2==0)   
                sum+=a[i];
        if(j++>0)
            printf("\n");
        printf("%d\n",sum);
    }    
    return 0;
}
