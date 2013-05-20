#include<stdio.h>
#include<string.h>
int main()
{
    int t,n,i,j,k,c=1,sum;
    int arr[50010];
    char ord[5];
    scanf("%d%*c",&t);
    while(t--)
    {
        printf("Case %d:\n",c++);
        scanf("%d%*c",&n);
        for(i=1;i<=n;i++)
            scanf("%d",arr+i);
            getch();
        while(scanf("%s",ord)!=EOF)
        {
            if(!strcmp("End",ord))
                break;;
            scanf("%d%d%*c",&k,&j);
            if(!strcmp("Add",ord))
                arr[k]+=j;
            else if(!strcmp("Sub",ord))
                arr[k]-=j;
            else
            {
                for(sum=0,i=k;i<=j;i++)
                    sum+=arr[i];
                printf("%d\n",sum);
            }
        }
    }
    return 0;
}
