//´Ó×Ö·û´®³é³öÊý×Ö
#include<iostream> 
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
    char expr[100];
    int top = 0;
    double opnd[100];
    
    gets(expr);
    
    for(int i = 0; expr[i]; i++)
    {
        int t, j;
        double sum = 0;
        if(isdigit(expr[i]))
        {
            for(j = i; isdigit(expr[j]); j++)
            {
                t = expr[j] - '0';
                sum = sum * 10 + t;
            }
            opnd[top] = sum;
            top++;
            i = j;
        }
    }
    
    for(int i = 0; i < top; i++)
        cout << opnd[i] << endl;
    
    system("pause");
    return 0;
}
