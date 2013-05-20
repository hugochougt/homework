#include<stdio.h>
int main()
{
    int a[100],i,t,k,c;
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
            c=0;
            k^=a[0];
            if(k<a[0])
                c++;
            for(i=1;i<t;i++)
            {
                k^=a[i-1];
                k^=a[i];
                if(k<a[i])
                c++;
            }
            printf("%d\n",c);    
        }
    }
    return 0;
}
