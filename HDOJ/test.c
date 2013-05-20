#include<stdio.h>
int main()
{
    int a[100],i,t,k,c,n;
    while(scanf("%d",&t)!=EOF)
    {
        if(0==t)    break;
        for(i=0,k=0;i<t;i++)
        {
            scanf("%d",a+i);
            k^=a[i];    
        }
        if(0==k)
            printf("0\n");
        else
        {
            for(i=0,c=0;i<t;i++)
            {
                n=k-a[i];
                if(a[i]<n)
                    c++;
            }
            printf("%d\n",c);    
        }
    }
    return 0;
}
