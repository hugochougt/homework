#include<stdio.h>
int main(void)
{
    char s[81];
    int n,i,j;
    while(scanf("%s%d",s,&n)!=EOF)
    {
         for(i=0;i<n;i++)
         {
            for(j=0;j<i;j++)
                printf(" ");    
            printf("%c\n",s[i]);
        } 
    }
    return 0;
}
