#include <stdio.h>

int main(void)
{
    char c;
    int n,count,count_n,tag;
    tag = 0;
    while( scanf("%c %d", &c,&n) && c!='@')
    {
        if(!tag)
        {
            tag = 1;
        }
        else
            printf("\n");
        for(count_n=0;count_n<n-1;count_n++)
        {
            for(count=0;count<n-count_n-1;count++)
            {
                printf(" ");
            }
            printf("%c", c);
            count=count_n;
            if(count)
            {
            while(count--)
                printf(" ");
            
            for(count=1;count<=count_n-1;count++)
                printf(" ");
            printf("%c", c);
            }
            printf("\n");
        }
        for(count=0;count<n*2-1;count++)
            printf("%c",c);
        printf("\n");
        getchar();
    }
    return 0;
}
