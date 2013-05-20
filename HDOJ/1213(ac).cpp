#include <iostream>
#define MaxNum 1002
using namespace std;
int map[MaxNum][MaxNum];
int N,M;
bool Visit[MaxNum];
void DFS(int i);
void Init()
{
    int i,j;
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            map[i][j]=0;
}
int DFSTraverse()
{
    int i,cnt=0;
    for(i=0;i<N;i++)
        Visit[i]=false;
    for(i=0;i<N;i++)
        if(Visit[i]==false)
            {DFS(i);cnt++;}
    return cnt;
}
void DFS(int i)
{
    Visit[i]=true;
    for(int k=0;k<N;k++)
        if(map[i][k]&&Visit[k]==false)
            DFS(k);
}
int main()
{
    int T,i,r,c;
    while(cin>>T)
    {
        while(T--)
        {
            cin>>N>>M;
        //========构造邻接矩阵======================
            Init();
            for(i=0;i<M;i++)
                {
                    cin>>r>>c;
                    map[c-1][r-1]=map[r-1][c-1]=1;
                }
        //===========进行DFS搜=======================
            cout<<DFSTraverse()<<endl;
            //if(T)cout<<endl;
        }
    }
}
