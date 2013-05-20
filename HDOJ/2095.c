#include<stdio.h>
#include<stdlib.h>
int a[1000000];
int cmp(int *a,int *b)
{
    if(*a==*b)
        return 0;
    else
        return *a-*b;    
}
int main()
{
    int n,i,tag,c;
    while(scanf("%d",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
            scanf("%d",a+i);
        qsort(a,n,sizeof(int),cmp);
         if(n<4)
        {
            if(a[1]==a[0])
                printf("%d\n",a[2]);
            else
                printf("%d\n",a[0]);    
        }
        else{
        for(i=0,c=1,tag=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
                c++;
            else
            {
                if(c%2==1)
                {
                    printf("%d\n",a[i]);
                    tag=1;
                    break;
                }
                else
                    c=1;    
            }
        }
        if(0==tag)  printf("%d\n",a[n-1]);}
    }
    return 0;
}
