//题6. 四则运算

#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<stdlib.h>

int A[7][7] = {3,3,2,2,2,3,3,
               3,3,2,2,2,3,3,
               3,3,3,3,2,3,3,
               3,3,3,3,2,3,3,
               2,2,2,2,2,1,0,
               3,3,3,3,0,3,3,
               2,2,2,2,2,0,1}; //存放运算符的优先顺序，3为>,2为<,1为＝

int isoperator(char optr)  //判断是否操作符 
{
    switch(optr)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '(':
        case ')':
        case '#':return 1;
        default:return 0;
    }
}

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
    }
}

char preced(char a, char b) //判断运算符的优先关系 
{
    int m, n;
    m = crd(a);
    n = crd(b);
    switch(A[m][n]) 
    {
        case 3:return '>';
        case 2:return '<';
        case 1:return '=';
    }
}

int push_opnd(double *opnd, char *expr, int top_opnd, int i)  //操作数压栈 
{
	int j;
	double suma = 0.0, sumb = 0.0;
	double e = 0.1, tmp;

	for(j = i; isdigit(expr[j]); j++)
	{
		tmp = expr[j] - '0';
		suma = suma * 10 + tmp;
	}
	if(expr[j] == '.')
	{
        for(j++; isdigit(expr[j]); j++)
        {
            sumb += (expr[j] - '0') * e;
            e /= 10;
        }
    }
	opnd[top_opnd] = suma + sumb;
	return j;
}

void operate(double *opnd, char *optr, int top_opnd, int top_optr)  
{ //计算并把结果压栈
    switch(optr[top_optr - 1])
    {
        case '+': opnd[top_opnd - 2] += opnd[top_opnd - 1];break;
        case '-': opnd[top_opnd - 2] -= opnd[top_opnd - 1];break;
        case '*': opnd[top_opnd - 2] *= opnd[top_opnd - 1];break;
        case '/': if(opnd[top_opnd - 1] == 0)
                  {
                        printf("Error! The divisor is 0\n");
                        exit(1);
                  }
                  opnd[top_opnd - 2] /= opnd[top_opnd - 1];
                  break;
    }
}

int main()
{
	double OPND[100];	//运算数栈
	char OPTR[100];		//运算符栈
	char EXPR[100];		//表达式
	char str[100];

	int top_opnd = 0;	//运算数栈顶计数器
	int top_optr = 0;	//运算符栈顶计数器
	int len;		//表达式长度
    int i;      //下标 
    
	printf("Input the Expression: ");
	gets(str);
	len = strlen(str);

	//在表达式前后加上'#'
	EXPR[0] = '#';
	for(i = 0; str[i] != '\0'; i++)
		EXPR[i + 1] = str[i];
	EXPR[len + 1] = '#';
	EXPR[len + 2] = '\0';
	
    OPTR[top_optr++] = '#';
    i = 1; 
	while(EXPR[i] != '#' || OPTR[top_optr - 1] != '#')
	{
		if(isdigit(EXPR[i]))
		{
			i = push_opnd(OPND, EXPR, top_opnd, i);
			top_opnd++;
		}
		else if(isoperator(EXPR[i]))
		{
			switch(preced(OPTR[top_optr - 1], EXPR[i]))
			{
                case '<': OPTR[top_optr++] = EXPR[i];
                          i++;
                          break;
                case '=': top_optr--;
                          i++;
                          break;
                case '>': operate(OPND, OPTR, top_opnd, top_optr);
                          top_opnd--;
                          top_optr--;
                          break;
            }
		}
	}
	
	printf("%.0lf\n", OPND[0]);
	
	return 0; 
}
