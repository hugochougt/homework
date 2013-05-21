#include <stdio.h>
int num[1001],p[1001];//有模板   五道题目基本上大同小异~~
void make_set(int e)
{
    p[e]=e;
    num[e]=1;
}
int find_set(int key)
{
    if(key!=p[key])p[key]=find_set(p[key]);
    return p[key];
}
void union_set(int s1,int s2)
{
    int p1,p2;
    if(s1==s2)return;
    p1=find_set(s1);
    p2=find_set(s2);
    if(p1!=p2)
    {
        if(num[p1]>=num[p2])
        {
            p[p2]=p1;
            num[p1]+=num[p2];
            num[p2]=0;
        }else if(num[p1]<num[p2])
        {
            p[p1]=p2;
            num[p2]+=num[p1];
            num[p1]=0;
        }
    }

}
int t,i,n,m,a,b,count,ta;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
            if(!n)break;
            scanf("%d",&m);
            for(i=1;i<=1000;i++)
            {
                p[i]=0;num[i]=0;
            }
            for(i=0;i<m;i++)
            {
                scanf("%d%d",&a,&b);
                if(find_set(a)==0)make_set(a);
                if(find_set(b)==0)make_set(b);
                union_set(a,b);
            }
            count=-1;
            ta=0;
            for(i=1;i<=n;i++)
            {

                if(num[i])
                {
                    count+=num[i];
                    ta++;
                }
            }
            printf("%d\n",n-count+ta);
        }
    }

