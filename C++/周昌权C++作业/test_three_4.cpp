#include<iostream>
#include<stdlib.h>

using namespace std;

class CFltArray
{
public:
    CFltArray(int sz);
    CFltArray(CFltArray &A);
    float& operator = (CFltArray A);
    float& operator [] (int i);
    void ReSize(int sz); 
    int GetSize();
    ~CFltArray();
    
private:
    int size;
    float *Arr;
};

//默认构造函数 
CFltArray::CFltArray(int sz)
{
    if(sz <= 0)
        exit(1);
    size = sz;
    Arr = new float[size];     
}

//析构函数 
CFltArray::~CFltArray()
{
    delete [] Arr;
}

//重置数组的大小
void CFltArray::ReSize(int sz)
{
    size = sz;
    Arr = new float[size];        
}

//通过下标返回数组元素
float& CFltArray::operator [](int i)
{
    if(i < 0 || i > size - 1)  
    {
        cout << "数组下标越界!" << endl; 
        exit(1);
    }
    return Arr[i];  
}

//返回当前数组的大小
int CFltArray::GetSize()
{
    return size;    
}

CFltArray::CFltArray(CFltArray &A)
{
    size = A.GetSize();
    Arr = new float[size]; 
    
    float *ap = A.Arr;
    float *tp = Arr;
    
    for(int i = 0; i < size; i++)
        *tp++ = *ap++;   
        
    cout << "拷贝构造函数被调用" << endl;
}

float& CFltArray::operator = (CFltArray A)
{
    size = A.size;
    Arr = new float[size];
      
    float *ap = A.Arr;
    float *tp = Arr;
      
    for(int i = 0; i<size; i++)
        tp[i] = ap[i];
    
    return Arr[size];
}

int main(void)
{
    CFltArray array(10); 
    for(int i = 0; i < 10; i++)
        array[i] = i;
    for(int i = 0; i < 10; i++)
        cout << array[i] << "  ";
    cout << endl;
    
    CFltArray Aarray = array;
    cout << "初始化后数组大小: " << Aarray.GetSize() << endl;
    cout << Aarray[8] << endl;
    
    array.ReSize(20);
    cout << "重置后数组大小: " << array.GetSize() << endl; 
    
    system("pause");
    return 0;    
}
