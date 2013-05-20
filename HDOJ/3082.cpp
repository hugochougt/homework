#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

int per_sc(char *str);

int main()
{
    char str[102];
    int t,i,n;
    double sum;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=0,sum=0.0;i<n;i++)
        {
            cin >> str;
            sum += 1.0 / double(per_sc(str));
        }
        cout.precision(2);      //格式化 
        cout.setf(ios::fixed);  // 输出 
        cout << 1.0/sum << endl;
    }
    return 0;
}

//返回一条串联电路上的电阻和 
int per_sc(char *str)
{
    int i,j,k,sum,tmp,SUM;
    SUM = 0;
    for(i = 0; str[i] != '\0'; i++)
    {
        j = i;
        while(isdigit(str[j]))
        {
            j++;
        }
        if(j-i>0)
        {
            //cout << "j = " << j << endl;
            j--;
            tmp = j;
            for(sum=0,k=1;tmp>=i;tmp--,k*=10)
            {
                sum += (str[tmp] - '0') * k;
            }
            i = j;
            //cout << "sum = " << sum << endl;
            SUM += sum;
        }
    }
    //cout << SUM << endl;    
    return SUM;
}
