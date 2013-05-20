#include<stdio.h>
#include<stdlib.h>
int cmp(const int *a, const int *b)
{
    int v=*a-*b;
    if(!v)  return 0;
    else    return v;   
}
int main(void)
{
    int a[15],i,j,c,n;
    while(scanf("%d",&a[0])!=EOF)
    {
        if(a[0]!=-1)
        {
            i=0;
            do{
                i++;
               scanf("%d",a+i); 
                }while(a[i]!=0);
                n=i;
            qsort(a, n, sizeof(int), cmp);
            for(i=0,c=0;i<n-1;i++)
                for(j=i+1;j<n;j++)
                    if(a[j]==a[i]*2)
                        c++;
            printf("%d\n",c);    
        } 
        else    break;   
    }    
    return 0;
}
