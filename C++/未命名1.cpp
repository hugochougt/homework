#include"iostream"
using namespace std;
int main()
{
    int i;
    static char c[]="sdfdsffdfa";
    for (i=0;c[i]!='\0';i++);
    
    cout<<i<<endl;
    system("PAUSE");
    return 0;
}
