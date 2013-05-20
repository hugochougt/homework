#include <stdio.h>

int main(void)
{
    int t,n,a,b,i;
    char x,y;
    
    scanf("%d%*c",&t);
    
    while(t--)
    {
         scanf("%d%*c",&n);
         
         a=b=0;
         
         for(i=0;i<n;i++)
         {
             scanf("%c %c%*c",&x,&y);
             
             if(x=='R'){
                   switch(y){
                        case 'P':b++;break;
                        case 'S':a++;break;     
                        default :break;
                             }     
                        }              
                        
             if(x=='S') {
                   switch(y){
                        case 'P':a++;break;
                        case 'R':b++;break;     
                        default :break;
                             }     
                        } 
         
             if(x=='P') {
                   switch(y){
                        case 'S':b++;break;
                        case 'R':a++;break;     
                        default :break;
                             }     
                        } 
         } 
         if(a>b)   printf("Player 1\n");
         else if(a<b)     printf("Player 2\n");
         else    printf("TIE\n");     
    }    
    return 0;
}
