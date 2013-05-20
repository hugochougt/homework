#include<stdio.h>
#include<string.h>
int main()
{
    char str[100],t;
    int n,i,len,sp,ep;
    scanf("%d%*c",&n);
    while(n--)
    {
        gets(str);
        if(str[0]=='-')
            sp=1;
        else
            sp=0;
        ep = strlen(str)-1;
        while('0'==str[ep])
            ep--;
        while(sp<ep)
        {
            t=str[sp];
            str[sp]=str[ep];
            str[ep]=t;
            sp++;ep--;
        }
        printf("%s\n",str);
    }
    return 0;
}
