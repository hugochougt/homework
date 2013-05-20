#include <stdio.h>

int main(void)
{
    int n,sum,i,j;
    
    while(scanf("%d",&n)!=EOF)
    {
        sum=0;
        if(((n-1)/2)%2==1){
            for(i=1,j=n;i<=j;i+=2,j-=2)
                sum+=i*i+j*j;
                printf("%d\n",sum);
            }
        else{
            for(i=1,j=n;i<j;i+=2,j-=2)
                sum+=i*i+j*j;
                printf("%d\n",sum+i*j); 
            } 
    }    
    system("pause");
    return 0;
}
