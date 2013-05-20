//Ω·ππÃÂ≈≈–Ú,qsort 
#include<stdio.h>
#include<stdlib.h>
struct c
{
    int x;
    int y;  
}d[100];

int cmp(const struct c *a, const struct c *b)
{
    if((*a).x == (*b).x)
        return (*a).y-(*b).y; 
    else
        return (*a).x-(*b).x;   
}   
int main(void)
{
    int i,j,n;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
            scanf("%d%d",&d[i].x,&d[i].y);
            
        qsort(d, n, sizeof(struct c), cmp);
        printf("\n\n"); 
        for(i=0;i<n;i++)
            printf("%d %d\n",d[i].x,d[i].y);
           
    }    
    return 0;
}
