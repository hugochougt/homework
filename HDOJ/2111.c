#include<stdio.h>//2111
#include<stdlib.h>
struct bb
{
    int pri;
    int vol;
}baby[111];

int main()
{
    int n,v,i,sum;
    int cmp(struct bb*,struct bb*);
    while(scanf("%d%d",&v,&n)!=EOF)
    {
        if(0==v) break;
        for(i=0;i<n;i++)
            scanf("%d%d",&baby[i].pri,&baby[i].vol);
        qsort(baby,n,sizeof(struct bb),cmp);
        
        for(i=0;i<n;i++)
            printf("%d %d\n",baby[i].pri,baby[i].vol);
        
        for(i=0,sum=0;i<n;i++)
        {
            if(v-baby[i].vol>0)
            {
                sum+=baby[i].pri*baby[i].vol;
                v-=baby[i].vol;
            }
            else
            {
                sum+=baby[i].pri*v;
                break;    
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
int cmp(struct bb *a,struct bb *b)
{
    return (*b).pri - (*a).pri;   
}
