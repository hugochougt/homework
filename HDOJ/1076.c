#include <stdio.h>

int main(void)
{
    int y,n,N;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d%d",&y,&N);
        while(N>0)
        {
            if((y%4==0 && y%100!=0)||y%400==0)
                N--;
                y++;   
        }    
        printf("%d\n",y-1);
    }    
    system("pause");
    return 0;
}
