#include<stdio.h>
int main(void)
{
    char str[81];
    int i,n,t,tmp,c=0;
    scanf("%d%*c",&t);
    while(t--)
    {
        scanf("%d %s",&n,str);
        tmp=n-1;
        printf("%d ",++c);
        for(i=0;i<tmp;i++)
            printf("%c",str[i]);
        for(i=n;str[i]!='\0';i++)
            printf("%c",str[i]);
        printf("\n");    
    }    
}
