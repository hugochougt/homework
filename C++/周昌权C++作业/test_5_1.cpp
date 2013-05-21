#include<iostream>
using namespace std;
class Complex
{
public:
    Complex(){}
    Complex(float r, float i)
    {
        real = r;
        image = i;    
    }
    Complex operator / (Complex C2);
    friend Complex operator * (Complex &C1, Complex &C2);
    Complex operator + (Complex C2);
    Complex operator + (float r);
    friend Complex operator - (Complex C1, Complex C2);
    friend Complex operator - (Complex C1, float r);
    void show();
    ~Complex(){}
private:
    float real;
    float image;
};

Complex Complex::operator / (Complex C2)
{
    Complex t;
    t.real = (real*C2.real+image*C2.image)/(C2.real*C2.real+C2.image*C2.image);
    t.image = (image*C2.real-real*C2.image)/(C2.real*C2.real+C2.image*C2.image);
    return t;
}

Complex operator * (Complex &C1, Complex &C2)
{
    Complex t;
    t.real = C1.real*C2.real-C1.image*C2.image;
    t.image = C1.real*C2.image+C2.real*C1.image;
    return t;
}

Complex Complex::operator + (Complex C2)
{
    return Complex(real+C2.real, image+C2.image);    
}

Complex Complex::operator + (float r)
{
    return Complex(real+r, image);  
}

Complex operator - (Complex C1, Complex C2)
{
    return Complex(C1.real-C2.real, C1.image-C2.image);    
}

Complex operator - (Complex C1, float r)
{
    return Complex(C1.real-r, C1.image); 
}

void Complex::show()
{
    cout << "( " << real << ", " << image << " )"<< endl;
}

int main()
{
    Complex C1(12, 8),C2(77, 3),C3;
    float r=4;
    cout << "real = " << r << endl;
    cout << "C1 = ";
    C1.show();
    cout << "C2 = ";
    C2.show();
    C3 = C1 - C2;
    cout << "C1 - C2 = ";
    C3.show();
    cout << "C1 + " << r << " = ";
    C3 = C1 + r;
    C3.show();
    cout << "C1 * C2 = ";
    C3 = C1 * C2;
    C3.show();
    system("pause");
    return 0;
}
