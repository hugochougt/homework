#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char str[220];
    int n,i,j,ii;
    while(scanf("%d%*c",&n)!=EOF)
    {
        if(0==n) break;
        gets(str);
        ii=strlen(str)/n;
        for(i=0;i<=ii;i++)
        {
            if(i%2==0)
            {
                int end=i*(n+1);
                for(j=n*i+1;j<=end;j++)
                    printf("%c",str[i]);
            }
            else
            {
                int end=n*i-n;
                for(j=n*i+1;j>end;j--)
                    printf("%c",str[j]);
            }
        }
        printf("\n");
    }
    return 0;
}
