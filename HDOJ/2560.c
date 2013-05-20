#include <stdio.h>

int main(void)
{
    int T,N,M,i,j,c,a;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&N,&M);
        c=0;
        for(i=0;i<N*M;i++)
        {
            scanf("%d",&a);
            if(1==a)
                c++;                  
        }      
        printf("%d\n",c);
    }                  
    return 0;    
}
