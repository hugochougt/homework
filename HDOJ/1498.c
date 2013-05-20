#include<stdio.h>
int main()
{
    int color[51];
    int n,k,x,i,tag;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if((0==k) && (0==n))   break;
        for(i=1;i<51;i++)
            color[i]=0;
        n*=n;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            color[x]++;    
        }
        tag=0;
        for(i=1;i<=50;i++)
        {
            if(color[i]>k)
            {
                if(!tag)
                {
                    printf("%d",i);
                    tag=1;
                }
                else
                    printf(" %d",i);
            }
        }
        if(tag)
            printf("\n");
        else
            printf("-1\n");
    }
    return 0;
}
