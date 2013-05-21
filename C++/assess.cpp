#include<iostream>
#include<cstring>
#include<cctype>
using namespace std;

int A[7][7] = {3,3,2,2,2,3,3,
               3,3,2,2,2,3,3,
               3,3,3,3,2,3,3,
               3,3,3,3,2,3,3,
               2,2,2,2,2,1,0,
               3,3,3,3,0,3,3,
               2,2,2,2,2,0,1 }; 
int crd(char c)     //寻找字符所在的行列坐标
{
    switch(c)
    {
        case'+': return 0;
        case'-': return 1;
        case'*': return 2;
        case'/': return 3;
        case'(': return 4;
        case')': return 5;
        case'#': return 6;
        default:break;
    }
}

char preced(char a, char b) //判断运算符的优先关系 
{
    int m, n;
    char k;
    m = crd(a);
    n = crd(b);
    cout << A[m][n] << endl;
    system("pause");
    if(A[m][n] == 3) 
        return '>';
    else if(A[m][n] == 2) 
        return '<';
    else if(A[m][n] == 1) 
        return '=';
}

int main()
{
    cout << preced('+', '*') << endl;
    system("pause");
    return 0;
}
