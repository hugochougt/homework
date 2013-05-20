#include <stdio.h>
int main()
{
    int a,b,n,res;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&a,&b);
        res=1;
        while(n--)
        {
            res*=b;
            b--;    
        }
        printf("%d\n",a*res);
    }
    return 0;
}
