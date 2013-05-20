#include<stdio.h>
int main(void)
{
    int i,j,t,black;
    char s[16],a[500];
    scanf("%d%*c",&t);
    while(t--)
    {
        gets(a);
        for(i=0,j=0,black=0; a[i] != '\0'; i++)
            if(a[i] == ' ')
                black=0;
            else if(black==0)
                {
                    s[j]=a[i];
                    j++;
                    black=1;
                }
        for(i=0;i<j;i++)
            if(isupper(s[i]))
                printf("%c",s[i]);
            else
                printf("%c",s[i]-32);
        printf("\n");
    } 
    return 0;
}
