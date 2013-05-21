#include<iostream>
using namespace std;
int main()
{
    int i;
    cout << "++i: ";
    for(i=1;i<=5;++i)
        cout << i << " ";
    cout << endl;
    cout << "i++: ";
    for(i=1;i<=5;i++)
        cout << i << " ";
    cout << endl;
    getchar();
    return 0;
}
