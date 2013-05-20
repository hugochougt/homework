
//2550
#include<stdio.h>
#include<string.h>
void main()
{
    int t,d,i,n,j;
    int a[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        memset(a,0,sizeof(a));
        while(n--)
        {
            
            scanf("%d%d",&i,&d);
            a[i]=d;
        }
        for(i=0;i<100;i++)
        {
            if(a[i]!=0)
            {
                while(a[i]--)
                {
                printf(">+");
                for(j=0;j<i-2;j++)
                {
                    printf("-");
                }
                printf("+>\n");
                }
                printf("\n");
            }
        }
        
        
    }
}
  
