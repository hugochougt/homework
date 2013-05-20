#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;

const int maxn=200005;
int wa[maxn],wb[maxn],wv[maxn],wt[maxn],r[maxn],sa[maxn];
char str[maxn];

int cmp(int *r,int a,int b,int l)
{
    return r[a]==r[b] && r[a+l]==r[b+l];
}
void da(int *r,int *sa,int n,int m)
{
    int i,j,p,*x=wa,*y=wb,*t;
    for(i=0;i<m;i++)
        wt[i]=0;
    for(i=0;i<n;i++)
        wt[x[i]=r[i]]++;
    for(i=1;i<m;i++)
        wt[i]+=wt[i-1];
    for(i=n-1;i>=0;i--)
        sa[--wt[x[i]]]=i;
    for(j=1,p=1;p<n;j*=2,m=p)
    {
        for(p=0,i=n-j;i<n;i++)
            y[p++]=i;
        for(i=0;i<n;i++)if(sa[i]>=j)
            y[p++]=sa[i]-j;
        for(i=0;i<n;i++)
            wv[i]=x[y[i]];
        for(i=0;i<m;i++)
            wt[i]=0;
        for(i=0;i<n;i++)
            wt[wv[i]]++;
        for(i=1;i<m;i++)
            wt[i]+=wt[i-1];
        for(i=n-1;i>=0;i--)
            sa[--wt[wv[i]]]=y[i];
        for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++)
            x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
    }
}

int rank[maxn],height[maxn];

void calheight(int *r,int *sa,int n)
{
    int i,j,k=0;
    for(i=1;i<=n;i++)
        rank[sa[i]]=i;
    for(i=0;i<n;height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; r[i+k]==r[j+k]; k++);
}

int main()
{
    int i;
    while(cin>>str)
    {
        int pos=strlen(str);
        str[pos]='$';
        cin>>str+pos+1;
        int n=strlen(str);

        for(i=0;i<n;i++)
            r[i]=(int)str[i];
        r[n]=0;
        da(r,sa,n+1,130);
        calheight(r,sa,n);
        int maxl=0;
        for(i=2;i<=n;i++)
        {
            int a=sa[i-1],b=sa[i];
            if((a<pos&&b>pos)||(a>pos&&b<pos))
                if(height[i]>maxl)
                    maxl=height[i];
        }
        printf("%d\n",maxl);

    }
    return 0;
}
