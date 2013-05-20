#include<stdio.h>
#include<math.h>
int prime(int n)
{
    int i,k=(int)sqrt(n);
    for(i=2;i<=k;i++)
    {
        if(n%i==0)
            return i;
    }
    return -1;
}
int main()
{
    int i,n=65537,tmp;
    for(i=3;i<=n;i+=2)
    {
        tmp=prime(i);
        if(tmp<0)
            printf("%10d",i);
    }
    system("pause");
}
