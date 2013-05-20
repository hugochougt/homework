#include<stdio.h>
#include<stdlib.h>
struct c
{
    int a;
    int b;    
}d[55];

int cmp(const struct c *x, const struct c *y)
{
    if((*x).a==(*y).a)
        return (*x).b-(*y).b; 
    else
        return (*x).a-(*y).a;   
}

int main(void)
{
    int i,j,k,n,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        
        for(i=0;i<n;i++)
            scanf("%d%d",&d[i].a,&d[i].b);
            
        qsort(d, n, sizeof(struct c), cmp);
        
        for(i=0;i<n;i++)
        {
            for(j=0;j<d[i].b;j++)
            {
                printf(">");
                for(k=1;k<d[i].a;k++)
                {
                    if(k==d[i].a-1)
                        printf("+>");
                    else if(k==1)
                        printf("+-");
                    else
                        printf("-");     
                }    
                printf("\n");
            }
            printf("\n");
        }    
    }  
    return 0;
}
