#include<stdio.h>
#include<stdlib.h>
struct c
{
    int x;
    int y;    
}d[401];

int cmp(const struct c *a, const struct c *b)
{
    if((*a).x==(*b).x)
        return (*a).y-(*b).y;
    else
        return (*a).x-(*b).x;        
}

void swap(int *A, int *B)
{
    int tmp;
    tmp=*A;
    *A=*B;
    *B=tmp;    
}

int main(void)
{
    int t,n,i,c;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&d[i].x,&d[i].y);
            if(d[i].x>d[i].y)
                swap(&d[i].x, &d[i].y);
                
        }
        qsort(d, n, sizeof(struct c), cmp);
        for(i=0,c=1;i<n-1;i++)
            if(d[i].y>d[i+1].x)
                c++;
        printf("%d\n",c*10);     
    }        
    return 0;
}
