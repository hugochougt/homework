#include<iostream>
using namespace std;
int main(void)
{
    int a[11]={0};
    int i,n;
    for(i=0;i<20;i++)
    {
        cin >> n ;
        a[n]++;    
    }    
    for(i=1;i<=10;i++)
        cout << i <<" "<< a[i] << endl;
    system("pause");
    return 0;
}
