#include <stdio.h>      //√∞≈›≈≈–Ú∑® 
#include <stdlib.h>

int main(void)
{
    int i,j,n,t;
    int *p=NULL;

    printf("Input n numbers:");

    scanf("%d",&n);

    p=(int *)malloc(n*sizeof(int));
    
    if(p==NULL) return 0;
    
    for(i=0;i<n;i++)
        scanf("%d",p+i);
        
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(*(p+j)>*(p+j+1))
            {
               t=*(p+j);
               *(p+j)=*(p+j+1);
               *(p+j+1)=t; 
            }
            
    for(i=0;i<n;i++)
        printf("%d%c",*(p+i),i<n-1?' ':'\n');
    
    free(p); 
    system("pause"); 
       
    return 0;
}
