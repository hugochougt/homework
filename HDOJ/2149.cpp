#include<iostream>
using namespace std;
main()
{
    int m,n,i;
    while(cin>>m>>n)
    {
        if(m<=n) 
        {
          for(i=m;i<n;i++)
           cout<<i<<' ';
           cout<<n<<endl;
        }
        else 
        {
            if(m%(n+1)) 
              cout<<m%(n+1)<<endl;
            else 
              cout<<"none"<<endl;
        }
    }
}
