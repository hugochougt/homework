#include <stdio.h>

int main(void)
{
    int t,a[3],b[3],i;
    
    scanf("%d",&t);
    
    while(t--)
    {
         for(i=0;i<3;i++)
             scanf("%d",a+i);
             
         for(i=0;i<3;i++)
             scanf("%d",b+i);
             
         if(a[0]>b[0])    printf("First\n");
         
         else if(a[0]<b[0])    printf("Second\n");
         
         else{
                  if(a[1]>b[1])    printf("First\n");
                  
                  else if(a[1]<b[1])   printf("Second\n");
                  
                  else {
                           if(a[2]>b[2])    printf("First\n");
                           
                           else if(a[2]<b[2])    printf("Second\n");
                           
                           else printf("Same\n");
                       }
              }            
    }
    return 0;
}
