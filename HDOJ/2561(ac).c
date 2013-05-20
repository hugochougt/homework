#include<stdio.h>
main()
{
    int T,i,n,a,f,s,m;
    for(scanf("%d",&T);T>0;T--)
    {
        scanf("%d",&n);
        f=100;
        s=100;
        for(i=0;i<n;i++)
        {
         scanf("%d",&a);
         if(a<=s) s=a;
         if(s<=f) {m=s;s=f;f=m;}
        }
        printf("%d\n",s);
    }
}
