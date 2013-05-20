#include<stdio.h>
int main()
{
    void swap(char *a, char *b);
    char str[8];
    int i,test,n,m,t;
    scanf("%d",&test);
    while(test--)
    {
        str[1]='Z';str[5]='A';
        str[2]='J';str[6]='C';
        str[3]='U';str[7]='M';
        str[4]='T';
        
        scanf("%d",&t);
        while(t--)
        {
            scanf("%d%d",&n,&m);
            swap(&str[n],&str[m]);    
        }
        
        i=1;
        while(str[i]!='J')
            i++;
        printf("%d\n",i);
    }
    return 0;
}

void swap(char *a, char *b)
{
    char t=*a;
    *a=*b;
    *b=t;    
}
