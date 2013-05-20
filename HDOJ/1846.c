#include<stdio.h>
#include<malloc.h>
int main(void)
{
    int i,n,m,t,*p,tag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        p = (int *)malloc((n+1)*sizeof(int));
        p[0] = 0;
        tag = 0;
        for(i=1;i<=n;i++)
        {
            if((i-tag)<=m)
                p[i]=1;
            else
                p[i]=0;
            if(p[i]==0)
                tag = i;   
        }
        if(p[n]==0)
            printf("second\n");
        else
            printf("first\n");
        free(p);
    }    
    return 0;
}
