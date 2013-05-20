//非递归 
#include <cstdio>
#include <cmath>
 
using namespace std;
 
#define N 13
 
int x[N];
 
bool isvalid(int k)
{
    int i;
    for(i=0; i<k; i++)
        if(x[i]==x[k] || abs(x[i]-x[k])==k-i)
            return false;
    return true;
}
int queen(int n)
{
    int k=0,count=0;
    x[k]=-1;
    while(k>=0)
    {
        x[k]++;
        while(x[k]<=n-1 && !isvalid(k))
			x[k]++;
        if(x[k]>n-1)
			k--;
        else if(k==n-1)
			++count;
        else
			x[++k]=-1;
    }
    return count;
}
int main()
{
    int n,ans[N]= {0};
    for(n=1; n<=11; n++)
        ans[n]=queen(n);
    while(scanf("%d",&n)!=EOF && n)
        printf("%d\n",ans[n]);
    return 0;
}