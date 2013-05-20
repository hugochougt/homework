#include <stdio.h>

int main(void)
{
    int B,C,n;
    scanf("%d",&C);
    while(C--)
    {
         scanf("%d",&n);
         B=0;
         while(n!=0)
         {
              if(n%2==1)
              {
                  B++;
                  n-=1;           
              }        
              if(n%2==0)
                  n/=2;  
         }          
         printf("%d\n",B);
    }    
    return 0;
}
