//随机数产生程序 
#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i,n,j;
    
    srand((unsigned)time(0));
    
     for(i=1,j=1;i<=100;i++,j++)
        {
            printf("%d",rand()%10); 
            if(i%4==0)               
                printf(" ");
            if(j%20==0)   
                printf("\n\n");    
        }
    printf("\n\n");      
    system("pause");
    return 0; 
}
