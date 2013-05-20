#include<stdio.h>
main()
{
    int T,n,i;
    long y;
    scanf("%d",&T);
    for(i=0;i<T;i++)
    {
        scanf("%ld %d",&y,&n);
        while(n!=0)
        {
            if((y%4==0&&y%100!=0)||y%400==0)
                n--;
                y++;
        }
        if(n==0)
            printf("%ld\n",y-1);
    }
}
