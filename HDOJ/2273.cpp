#include<cstdio>
using namespace std;
int main()
{
    int N,L[101],S[101];
    double t;
    while(scanf("%d",&N)!=EOF)
    {
        int sum=0,min=11;
        for(int i=0;i<N;i++)    
        {
            scanf("%d%d",&L[i],&S[i]);
            sum+=L[i];
            if(min>S[i])
                min=S[i];
        }
        t=(double)sum/(double)min;
        printf("%.2lf\n",t);
    }
    return 0;
}
