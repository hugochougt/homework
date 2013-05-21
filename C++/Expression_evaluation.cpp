//Expression evaluation
#include<iostream> 
#include<cstdio>
#include<cctype>
using namespace std;

int prr[7][7] = {   1, 1, -1, -1, -1, 1, 1,
                    1, 1, -1, -1, -1, 1, 1,
                    1, 1, 1, 1, -1, 1, 1,
                    1, 1, 1, 1, -1, 1, 1,
                    -1, -1, -1, -1, -1, 0, 4,
                    1, 1, 1, 1, 4, 1, 1,
                    -1, -1, -1, -1, -1, 4, 0 };  //1表示>, 0表示=, -1表示< 

//判断是否操作符 
bool isoperator(char ch)
{
    switch(ch)
    {
        case '(':
        case ')':
        case '+':
        case '-':
        case '*':
        case '/':return true;
        default:return false;
    }
}

//建立操作符优先级的表 
int priority(char c)
{
    switch(c)
    {
        case '+':return 0;
        case '-':return 1;
        case '*':return 2;
        case '/':return 3;
        case '(':return 4;
        case ')':return 5;
        case '#':return 6;
        default:cout << "ERROR" << endl; exit(1);
    }
}

char oprt_cmp(char former, char latter) 
{
    int i = priority(former);
    int j = priority(latter);
    
    switch(prr[i][j])
    {
        case 1:return '>';
        case 0:return '=';
        case -1:return '<';
        case 4:cout << "ERROR" << endl; exit(1);
    }
}

int push_opnd(double *stack, char *ex, int top_opnd, int i)
{
    int t, j;
    double sum = 0.0;
    for(j = i; isdigit(ex[j]); j++)
    {
        t = ex[j] - '0';
        sum = sum * 10.0 + t;
    }
    //cout << sum << endl;
    stack[top_opnd] = sum;
    return j;
}

void evaluate(double *opnd, int top, char optr)
{
    switch(optr)
    {
        case '+' : opnd[top - 2] += opnd[top - 1];return ;
        case '-' : opnd[top - 2] -= opnd[top - 1];return ;
        case '*' : opnd[top - 2] *= opnd[top - 1];return ;
        case '/' : opnd[top - 2] /= opnd[top - 1];return ;
    }
}

int main()
{
    char str[100];
    char *expr; //表达式 
    char *oprt; //操作符 
    double *opnd;   //操作数 
    int len, top_opnd, top_oprt; //栈顶 
    
    top_opnd = 0;
    top_oprt = 0;
    
    gets(str);
    
    len = strlen(str);
    
    oprt = new char[len];
    opnd = new double[len];
    expr = new char[len + 2];
    
    expr[0] = '#';
    expr[len + 1] = '#';
    
    for(int i = 0; i < len; i++)
        expr[i+1] = str[i];
    expr[len+2] = '\0';
    
    //puts(expr);
    
    oprt[top_oprt++] = '#';
    
    for(int i = 1; i < len + 2; i++)
    {
        if(isdigit(expr[i]))
        {
            i = push_opnd(opnd, expr, top_opnd, i);
            top_opnd++;
        }
        else if(isoperator(expr[i]))
        {
            switch(oprt_cmp(oprt[i-1], expr[i]))
            {
                case '=': top_oprt--;
                          break;
                
                case '>': oprt[top_oprt++] = expr[i];
                          i++;
                          break;
                case '<': evaluate(opnd, top_opnd, oprt[top_oprt]);
                          top_opnd--;
                          top_oprt--;
                          break;
            }
        }
    }
    
    cout << opnd[0] << endl;
    
    delete oprt;
    delete opnd;
    delete expr;
    
    system("pause");
    return 0;
}
