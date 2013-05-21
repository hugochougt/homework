#include<iostream>
using namespace std;
class B1
{
    public:
        B1(int i)
        {
            cout << "Constructing B1 " << i << endl;
        }
        ~B1()
        {
            cout << "Destructing B1" << endl;   
        }
};

class B2
{
    public:
        B2(int j)
        {
            cout << "Constructing B2 " << j << endl;
        }
        ~B2()
        {
            cout << "Destructing B2 " << endl;   
        }
};
class B3
{
    public:
        B3()
        {
            cout << "Constructing B3 *" << endl;
        }
        ~B3()
        {
            cout << "Destructing B3" << endl;   
        }
};

class C : public B2, public B1, public B3  //注意基类名的顺序 
{
    public: 
        C(int a, int b, int c, int d) : B1(a), memberB2(d),memberB1(c),B2(b){}
    private:
        B1 memberB1;
        B2 memberB2;
        B3 memberB3;
};

int main(void)
{
    C obj(1,2,3,4);
    system("pause");
    return 0;    
}
