#include<stdio.h>
struct ss{
    int ID;
    int score;
}std[1005];
int cmp_s(const struct ss *a,const struct ss *b)
{
    if(b->score==a->score)
        return a->ID-b->ID;
    return b->score-a->score;    
}
/*
int cmp_ID(const struct ss *a,const struct ss *b)
{
    return b->ID-a->ID;    
}
*/
int main()
{
    int Jackson,i,rank,num;
    while(scanf("%d",&Jackson)!=EOF)
    {
        i=0;
        while(scanf("%d%d",&std[i].ID,&std[i].score)!=EOF)
        {
            if(std[i].ID==0&&std[i].score==0)
                break;
            i++;
        }
        num=i;
        //printf("Num: %d\n",num);
        //qsort(std,num,sizeof(struct ss),cmp_ID);
        qsort(std,num,sizeof(struct ss),cmp_s);
        rank=1;
        for(i=0;i<num;i++)
        {
            if(Jackson==std[i].ID)
            {
                printf("%d\n",rank);
                break;
            }
            else
            {
                rank++;    
            }
        }
    }
    return 0;
}
