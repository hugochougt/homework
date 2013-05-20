#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int cmp(const char *a, const char *b)
{
        return strcmp(*a,*b);           
}
int main()
{
    char s[5][5];
    int i,n;
    scanf("%d%*c",&n);
    while(n--)
    {
        for(i=0;i<5;i++)
            scanf("%s",s[i]);
        qsort(s,5,sizeof(s),cmp);
        printf("%s\n",s[3]);    
    }
    return 0;
}
