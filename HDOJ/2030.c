#include<stdio.h>
#include<string.h>
int main(void)
{
    char c;
    int t,count;
    scanf("%d%*c",&t);
    while(t--)
    {
        count = 0;
        while((c = getchar()) != '\n')
        {
            if(c < 0)
                count++;    
        }
        printf("%d\n",count/2);
    }
    return 0;
}
