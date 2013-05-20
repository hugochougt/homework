#include<stdio.h>
#include<stdlib.h>
struct c
{
    int s;
    int e;  
}d[103];

int cmp(const struct c *a, const struct c *b)
{
    if((*a).e == (*b).e)    
        return (*a).s - (*b).s;
    else
        return (*a).e - (*b).e;
}

int main(void)
{
    int i,j,k,n,count,eTime;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&d[i].s,&d[i].e);
        
        qsort(d, n, sizeof(struct c), cmp);
        eTime=d[0].e;
        for(i=1,count=1;i<n;i++)
            if(eTime<=d[i].s)
            {
                count++;
                eTime=d[i].e;
            }
        printf("%d\n",count);            
    }    
    return 0;
}
