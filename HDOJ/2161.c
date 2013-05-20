#include <stdio.h>
#include<math.h>
int main(void)
{
    int n,i,blank,c=0;
    
    while(scanf("%d",&n),n>0)
    {
        blank=1;
        
        c++;                 

        if(n==1||n==2)    printf("%d: no\n",c);          
    
        else  {
              for(i=2;i<=(int)sqrt(n);i++)
                if(n%i==0)
                {
                    blank=0;
                    break;    
                }     
                if(blank)   printf("%d: yes\n",c);
                else        printf("%d: no\n",c);             
        }                      
    }    
    return 0;
}
