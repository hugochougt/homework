#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
//#define OVERFLOW 0

//二叉树节点类型
typedef enum { INT, CHAR } ElemTag; //INT为实型，CHAR为字符型 

//二叉树数据域 
typedef struct TElemTag
{
    ElemTag tag;  
    union
    {
        int num;
        char c;
    };
} TElemTag;

//二叉树链式存储结构 
typedef struct BiTNode
{
    TElemTag data; //数据域 
    struct BiTNode *lchild, *rchild;    //左右孩子指针 
} BiTNode, *BiTree;

typedef BiTree SElemType;   //栈SqStack的元素

//栈的顺序存储结构 
#define STACK_INIT_SIZE 30  //初始存储空间 
#define STACKINCREMENT 5    //存储空间增量 

typedef struct SqStack
{
    SElemType *base;
    SElemType *top;
    int stacksize;
} SqStack;

int InitStack(SqStack *S)
{
    (*S).base = (SElemType *) malloc (STACK_INIT_SIZE * sizeof(SElemType));
    if(!(*S).base)
        exit(OVERFLOW);
    (*S).top = (*S).base;
    (*S).stacksize = STACK_INIT_SIZE;
    return OK;
}

int StackEmpty(SqStack S)
{
    if(S.top == S.base)
        return TRUE;
    else
        return FALSE;
}

int Push(SqStack *S, SElemType e)    //元素e压栈 
{
    if((*S).top - (*S).base >= (*S).stacksize)
    {//栈满，追加存储空间 
        (*S).base = (SElemType *) realloc((*S).base, ((*S).stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!(*S).base)  //存储分配失败 
            exit(OVERFLOW);
        (*S).top = (*S).base + (*S).stacksize;
        (*S).stacksize += STACKINCREMENT;
    }
    *((*S).top)++ = e;
    return OK;
}

int Pop(SqStack *S, SElemType *e)
{
    if((*S).base == (*S).top)
       return ERROR;
    *e = *--(*S).top;
    return OK;
}

int GetTop(SqStack S, SElemType *e)
{
    if(S.top > S. base)
    {
        *e = *(S.top - 1);
        return OK;
    }
    return ERROR;
}
