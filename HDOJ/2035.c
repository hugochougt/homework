#include<stdio.h>
int main(void)
{
    int a,b,res,i;
    while(scanf("%d %d",&a,&b)!=EOF,a||b)
    {
        
        for(i=0,res=1;i<b;i++)
        {
            if(a>999)
                a=a%1000;
            res=res*a; 
            if(res>999)
                res=res%1000;   
        }  
        printf("%d\n",res%1000);
    }    
    return 0;
}
