//Evaluation of postfix expression
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define true 1
#define false 0

struct stack
{
    int top;
    double item[20];    
};

double eval(char[]);
double pop(struct stack *);
void push(struct stack *p, double e);
double oper(int ,double ,double );

int main()
{
    char expr[20];
    int pos = 0;
    printf("Enter the postfix expression: ");
    gets(expr);
    printf("\n\tThe value is %f\n",eval(expr));
    system("pause");
    return 0;
}

double oper(int sy, double op1, double op2)
{
    switch(sy)
    {
        case '+':return (op1+op2);
        case '-':return (op1-op2);
        case '*':return (op1*op2);
        case '/':return (op1/op2);
        case '$':return (pow(op1, op2));
        default:printf("Illegal operation\n");
    }    
}

double eval(char expr[])
{
    int c,pos;
    double opnd1,opnd2,value;
    struct stack opndstk;
    opndstk.top = -1;
    
    for(pos = 0; (c = expr[pos]) != '\0'; pos++)
        if(isdigit(c))
            push(&opndstk, (double)c-'0');
        else
        {
            opnd2 = pop(&opndstk);
            opnd1 = pop(&opndstk);
            value = oper(c, opnd1, opnd2);
            push(&opndstk, value);
        }
    return pop(&opndstk);
}

void push(struct stack *p, double e)
{
    if(p -> top != 19)
    {
        p -> top++;
        p -> item[p -> top] = e;    
    }    
    else
        printf("\n\tStack Overflow\n");
}

double pop(struct stack *p)
{
    double x,e,k,*px,i;
    if(p -> top != -1)
    {
        x = p -> item[p -> top];
        p -> top--;    
    }
    else
        printf("Stack Underflow\n");
    return x;
}
