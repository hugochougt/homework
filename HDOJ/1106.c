#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    if(*a==*b)
        return 0;
    else
        return *a-*b;    
}
int main(void)
{
    char s[1007];
    int a[600],i,j,k;
    while(gets(s))
    {
        for(i=0,j=0;i<strlen(s);i++)
            {
                if(s[i]=='5')
                    continue;
                else{
                    for(k=i;s[k]!='5';k++)
                        a[j]+=s[k]-'0';
                        j++;  
                    }  
            }  
        qsort(a, j, sizeof(int), cmp);
        for(i=0;i<j;i++)
            printf("%d%c",a[i],i<j-1?' ':'\n');  
    }    
    return 0;
}
