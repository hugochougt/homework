#include<stdio.h>
int A[1002];
int find(int x)
{
    int r=x;
    while(A[r]!=r)
        r=A[r];
    return r;
}
void merge(int a, int b)
{
    int fa,fb;
    fa=find(a);
    fb=find(b);
    if(fa!=fb)
        A[fa]=fb;
}
int main(void)
{
    int n,m,x,y,i,c,T,tag=0;
    scanf("%d",&T);
    while(T--) 
    {
        scanf("%d%d",&n,&m);
        for(i=1;i<=n;i++)
            A[i]=i;
        for(i=1;i<=m;i++)
        {
            scanf("%d%d",&x,&y);
            merge(x,y);    
        }           
        for(i=1,c=0;i<=n;i++)
            if(A[i]==i)
                c++;
        printf("%d\n",c);
    }
    return 0;
}
