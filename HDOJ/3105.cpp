#include <iostream>
#include <cstring>
using namespace std;
const int N = 49;
using namespace std;
int main()
{
    int arr[N+1],t,i,*p,tag;
    while(cin >> t)
    {
        p = new int[t];
        for(i=0;i<t;i++)
            cin >> *(p+i);
        if(t<9)
            cout << "No" << endl;
        else
        {
            memset(arr,0,N+1);
            for(i=0;i<t;i++)
                arr[*(p+i)]++;
            tag = 1;
            for(i=1;i<=N+1;i++)
                if(!arr[i])
                {
                    tag = 0;
                    break;   
                }
            if(tag)
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
