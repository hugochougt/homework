#include<stdio.h>
#include<ctype.h>
int main(void)
{
    char ch;
    int n,i,sum,T,a[27],A[27];
    for(i=1;i<=26;i++)
        a[i]=(-i);
    for(i=1;i<=26;i++)
        A[i]=i;
    scanf("%d%*c",&T);
    while(T--)
    {
        scanf("%c %d%*c",&ch,&n);
        if(isupper(ch))
            sum=A[ch-'A'+1]+n;
        else if(islower(ch))
            sum=a[ch-'a'+1]+n;
        printf("%d\n",sum);
        }
    return 0;
}
