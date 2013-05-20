#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int t,n,k,i,j,c=1,sum;
    int arr[50010];
    char ord[5];
    cin>>t;
    while(t--)
    {
        cout << "Case " << c++ << ":" << endl;
        cin >> n;
        for(k=1;k<=n;k++)
        {
            cin >> arr[k];
        }
        while(cin >> ord)
        {
            if(!strcmp("End",ord))
                break;
            cin >> i >> j;
            if(!strcmp("Add",ord))
                arr[i]+=j;
            else if(!strcmp("Sub",ord))
                arr[i]-=j;
            else
            {
                for(sum=0,k=i;k<=j;k++)
                    sum+=arr[k];
                cout << sum << endl;
            }
        }
    }
    return 0;
}
