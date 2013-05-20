#include<stdio.h>
#include<string.h>
int main()
{
    int n,i,j,k,nn,count;
    char str[100010],tmp[100010],tar[100010];
    while(scanf("%d",&n)!=EOF)
    {
        nn=n*2;
        for(i=1;i<=nn;i++)
        {
            str[i]=tmp[i]=i;
        }
        str[i]=tmp[i]=tar[i]='\0';
        count=0;
        while(1)
        {
            for(i=1,j=n+1;j<=nn;i+=2,j++)
            {
                tar[i]=tmp[j];
            }
            for(i=2,j=1;j<=n;i+=2,j++)
            {
                tar[i]=tmp[j];    
            }
            count++;
            if(!strcmp(str,tar))
            {
                printf("%d\n",count);
                break;
            }
            else
                strcpy(tmp,tar);
        }
    }
    return 0;
}
