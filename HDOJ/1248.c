#include<stdio.h>
int main(void)
{
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        while(N>0)
        {
            if(N%150==0)
            {
                printf("0\n");
                break;
            }
            else   if(N%200==0)
            {
                printf("0\n");
                break;
            }
            else    if(N%350==0)
            {
                printf("0\n");
                break;
            }
            else    if(N>350)
                N-=350;
            else    if(N>200)
                N-=200;
            else    if(N>150)
                N-=150;
            else{
                printf("%d\n",N);
                break;
            }
        }    
    }    
    return 0;
}
