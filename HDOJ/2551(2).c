#include<stdio.h>
int pow3(int a)
{
    return a*a*a;    
}
int main(void)
{
    int t,n,c,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        i=1;
        c=0;
        do{
            n-=pow3(i)
            c++;    
        }while(n>0);
        printf("%d\n",c);
    }        
    return 0;
}
