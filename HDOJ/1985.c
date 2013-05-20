#include <stdio.h>

int main(void)
{
    int t,i=0;
    double m;
    char s[3];
    
    scanf("%d",&t);
    
    while(t--)
    {
         i++;
         
         scanf("%lf %s",&m,s);
         
         if(!strcmp(s,"kg"))  printf("%d %.4lf lb\n",i,2.2046*m);
         
         else if(!strcmp(s,"lb"))   printf("%d %.4lf kg\n",i,0.4536*m);
         
         else if(!strcmp(s,"l"))    printf("%d %.4lf g\n",i,0.2642*m);
         
         else    printf("%d %.4lf l\n",i,3.7854*m);
    }  
    return 0;  
}
