#include<stdio.h>
#include<stdlib.h>
struct pp{
    int st;
    int et;
}p[102];

int cmp(struct pp *a, struct pp *b)
{
    if((*a).et == (*b).et)    
        return (*a).st - (*b).st;
    else
        return (*a).et - (*b).et;

}

int main()
{
    int i,day,n;
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n) break;
        for(i=0;i<n;i++)
        {
            scanf("%d",&p[i].st);
            scanf("%d",&p[i].et);
        }
        qsort(p,n,sizeof(struct pp),cmp);
        day=1;
        for(i=1;i<n;i++)
        {
            if(p[i].st<=p[i-1].et)
                day++;
        }
        printf("%d\n",day);
    }
    return 0;
}
