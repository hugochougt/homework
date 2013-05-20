#include<stdio.h>
#include<stdlib.h>
int main()
{
    int i,j,n,tag;
    int a[105][8],al[54];
    while(scanf("%d",&n)!=EOF)
    {
        if(0==n) break;
        for(i=0;i<n;i++)
            for(j=0;j<6;j++)
                scanf("%d",&a[i][j]);
        if(n<9)
            printf("No\n");
        else
        {
            
            memset(al,0,sizeof(int)*54);
                
            for(i=0;i<n;i++)
                for(j=0;j<6;j++)
                    al[a[i][j]]++;
                    
            //for(i=1;i<50;i++)
            //    printf("%d ",al[i]);
                
            tag = 1;
            for(i=1;i<50;i++)
                if(0==al[i])
                {
                    tag = 0;
                    break;    
                }
            if(tag)
                printf("Yes\n");
            else
                printf("No\n");
        }    
    }
    return 0;
}
