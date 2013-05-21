#include<iostream>
using namespace std;
class complex
{
public:
    complex(int r,int i)
    {
        real = r;
        imag = i;    
    }
    friend ostream & operator<<(ostream &out, const complex &c);
private:
    int real,imag;
};

ostream & operator<<(ostream &out, const complex &c)
{
    cout << "( " << c.real << ", " << c.imag << " )" << endl;
    return out;    
}

int main()
{
    complex c1(44,12),c2(11,8);
    cout << c1 << c2;
    system("pause");
    return 0;
}
