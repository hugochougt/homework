//转动惯量
#include<iostream> 
using namespace std;

const double k = 0.000811;
const double I0 = 0.00408;
const double IBall = 40.85e-6;

int main()
{
    int x;//离转轴距离 单位cm 
    double t;//周期 单位s 
    double IEx, ITh, per;
    while(cin >> x >> t)
    {
        IEx = 0.5 * (k * t * t - I0); //实验值 
        ITh = IBall + 0.2397 * x * x / 10000;   //理论值 
        per = (ITh - IEx) / ITh * 100;  //百分误差 
        cout << IEx << endl;
        cout << ITh << endl;
        cout << per << "%" << endl;
    }
    return 0;
}
