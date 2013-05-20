#include<stdio.h>
int main(void)
{
    int i,n,T,tag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        tag=0;
        for(;n!=1;)
        {
            if(n%2==1)
            {
                if(!tag)
                    printf("%d",n);
                else
                    printf(" %d",n);
                tag++;
            }
            if(n%2==1)
                n=n*3+1;
            else
                n/=2;    
        }
        if(0==tag)    
            printf("No number can be output !\n");
        else
            printf("\n");
    }    
    return 0; 
}
