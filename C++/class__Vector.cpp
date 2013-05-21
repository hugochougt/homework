#include "iostream.h"
using namespace std;
class Vector
{
private:
	int *data;
	int size;
public:
	Vector(int v[]);
	~Vector();
	Vector(const Vector &v);
	Vector &operator=(const Vector &v);
	int &operator[](int index);
	friend ostream & operator << (ostream &out, const Vector &v);
};
Vector::Vector(int v[])
{
    data = v;    
}
Vector::~Vector()
{
    delete []data;
}
Vector::Vector(const Vector &v)
{
    data = v.data;
    size = v.size;    
}
Vector & Vector::operator=(const Vector &v)
{
    if(this != &v)
    {
        size = v.size;
        delete []data;
        data = new int[size];
        for(int i=0;i<size;i++)
            data[i]=v.data[i];
    }
        
    return *this;    
}
int& Vector::operator[](int index)
{
    return data[index];
}
ostream & operator << (ostream &out,const Vector &v)
{
    for(int i=0;i<v.size;i++)
        cout << v.data[i] << " ";
    return out;   
}
int main()
{
    int a[5]={1,2,3,4,5};
    Vector v(a);
    cout << v;
    system("pause");
    return 0;    
}
