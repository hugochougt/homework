#include<iostream>
using namespace std;
class B
{
    public:
        B(int i, int j)
        {
            b1 = i;
            b2 = j;    
        }
        void Print()
        {
            cout << b1 << "," << b2 << endl;   
        }
    private:
        int b1,b2;
};
class A
{
    public:
        A(int i, int j, int k):b(i,j)
        {
            a = k;    
        }
        void Print()
        {
            b.Print();
            cout << a << endl;    
        }
    private:
        B b;
        int a;
};
int main()
{
    B b(7,8);
    b.Print();
    A a(4,5,6);
    a.Print();
    system("pause");
    return 0;
}
