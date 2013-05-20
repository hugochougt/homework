#include<stdio.h>
#include<malloc.h>
int main()
{
    int t,n,m,i,*p,tag;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        if(m>=n)
            printf("Grass\n");
        else{
            p = (int *)calloc(n+1, sizeof(int));
            for(i=1,tag=0;i<=n;i++)
                if(i-tag<=m)
                    p[i]=1;
                else
                    tag=i;
            if(p[n])    printf("Grass\n");
            else        printf("Rabbit\n");
            free(p);        
        }    
    }
    return 0;
}
