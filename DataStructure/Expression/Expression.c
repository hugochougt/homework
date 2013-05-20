#include"Expression.h"

//判断是否操作符
int isoperator(char optr)
{
    switch(optr)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^': return TRUE;
        default: return FALSE;
    }
}

//判断字符a的类型
void Judge(BiTree *E, char a)
{
    if(isdigit(a))	//a是常量
    {
        (*E) -> data.tag = INT;
        (*E) -> data.num = a - '0';
    }
    else	//a为字符
    {
        (*E) -> data.tag = CHAR;
        (*E) -> data.c = a;
    }
}

int ReadExpr(BiTree *E, char *expr)
{
    int i, len;		//len为expr的长度
    SqStack S;		//操作符栈
    BiTree p, q;	//辅助变量
     
    gets(expr);
    len = strlen(expr);
    //printf("len = %d\n", len);
    
    (*E) = (BiTree)malloc(sizeof(BiTNode));	//申请根节点
    (*E) -> lchild = NULL;
    (*E) -> rchild = NULL;
    
    if(len == 1)	//表达式长度为1时
    {
        if(isdigit(expr[0]))
        {
            (*E) -> data.tag = INT;
            (*E) -> data.num = expr[0] - '0';
            return OK;
        }
        else if(isalpha(expr[0]))
        {
            (*E) -> data.tag = CHAR;
            (*E) -> data.c = expr[0];
            return OK;
        }
        else
        {
            printf("输入的字符不是运算符也不是变量常量，错误！\n");
            return ERROR;
        }
    }
    else
    {
        Judge(E, expr[0]);
        InitStack(&S);//初始化栈
        q = (*E);
        
        Push(&S, q);//
        Push(&S, q);//根结点入栈两次是为判断先序输入的表达式是不是正确的表达式
        
        for(i = 1; i < len && !StackEmpty(S); i++)
        {
            p = (BiTree)malloc(sizeof(BiTNode));
            Judge(&p, expr[i]);
            p -> lchild = NULL;
            p -> rchild = NULL;
            
            if(isoperator(expr[i])) //是运算符,运算符入栈
            {
                if( !q -> lchild )	//左孩子不空,往左走
                {
                    q -> lchild = p;
                    Push(&S, p);
                    q = p;
                }
                else				//否则右孩子不空,往右走
                {
                    q -> rchild = p;
                    Push(&S, p);
                    q = p;
                }
            }
            else	//不是运算符,出栈
            {
                if( !q -> lchild )
                {
                    q -> lchild = p;
                    Pop(&S, &q);
                }
                else
                {
                    q -> rchild = p;
                    Pop(&S, &q);
                } 
            }
        }//end for
        
        if(StackEmpty(S) && i >= len)
        {
            //printf("SM:%d  i:%d", StackEmpty(S), i);
            return OK;//表达式为前缀表达式
        }
        else
        {
            //printf("SM:%d  i:%d", StackEmpty(S), i);
            return ERROR; //不是前缀表达式
        }
    }
}

//如果两个字符是运算符，比较两个运算符的优先级，a比b优先，返回OK，否则返回ERROR
int PriCompare(char a, char b)
{
    if(isoperator(a) && isoperator(b))
    {
        if(a == '^')
        {
            if(b != '^')
                return OK;	//a的优先级比b高
            else
                return ERROR;
        }
        else if( a == '*' || a == '/')
        {
            if(b == '*' || b == '/' || b == '^')
                return ERROR;	
            else
                return OK;
        }
        else	//其余a的优先级不比b高
            return ERROR;
    }
    else	//不是运算符
        return ERROR;
}

//中序遍历输出中序缀表达式
void WriteExpr(BiTree E)
{
    if(E)//树不为空
    {
		//先递归左子树
        if(E -> lchild && E -> lchild -> data.tag == CHAR)//左孩子不空且为字符
		{
			if(PriCompare(E -> data.c, E -> lchild -> data.c))//E的优先级比其左孩子的高
			{												  //带括号输出表达式
				printf("(");
				WriteExpr(E -> lchild);
				printf(")");
			}
			else//不带括号输出左子树
				WriteExpr(E -> lchild);
		}
		else//左子树
			WriteExpr(E -> lchild);
		
		//访问并输出根节点
		if(E -> data.tag == INT)
		{
			printf("%d", E -> data.num);
		}
		else
		{
			printf("%c", E -> data.c);
		}

		//后递归右子树
		if(E -> rchild && E -> rchild -> data.tag == CHAR)//右孩子不空且为字符
		{
			if(PriCompare(E -> data.c, E -> rchild -> data.c))//E的优先级比其右孩子的高
			{												 //带括号输出表达式
				printf("(");
				WriteExpr(E -> rchild);
				printf(")");
            }
			else//不带括号输出右子树
				WriteExpr(E -> rchild);
		}
		else//输出右子树
			WriteExpr(E -> rchild);
    }
}

//对表达式中的所有变量V的赋值，参数flag为表示是否赋值过的标志
void Assign(BiTree *E,char V,int c,int *flag)
{
	if(*E)
	{
		if((*E)->data.tag==CHAR&&(*E)->data.c==V)//如果找到要赋值的变量，赋值
		{
            (*E)->data.tag=INT;
            (*E)->data.num=c;
            *flag=1;
        }
		Assign(&((*E)->lchild),V,c,flag);//递归左子树
		Assign(&((*E)->rchild),V,c,flag);//递归左子树
	}
}
	
int powINT(int x, int exp)
{
    int i, result = 1;
    for(i = 1; i <= exp; i++)
        result *= i;
    return result;
}

int Operate(int a, char oprt, int b)
{
    switch(oprt)
    {
        case '+':return a + b;
        case '-':return a - b;
        case '*':return a * b;
        case '/':
            if(b != 0)
                return a / b;
            else
            {
                printf("除数不能为0\n");
                break;
            }
        case '^':return powINT(a, b);
        default:break;
    }
}

//检查是否还有没赋值的变量 
int Check(BiTree E)
{
    if(E && E -> data.tag == CHAR)//树不空且为结点为字符 
    {
        if(isalpha(E -> data.c)) 
            return ERROR; 
            
        Check(E -> lchild);
        Check(E -> rchild);
        return OK;
    }
}

int Value(BiTree E)
{
    if(E)
    {
        //结点的左右孩子空, 是叶子结点, 返回其值 
        if(!E -> lchild && !E -> rchild && E -> data.tag == INT)
            return E -> data.num;
        
        //以后根遍历次序求解表达式的值
        return Operate(Value(E -> lchild), E -> data.c, Value(E -> rchild));
    }
}

void CompoundExpr(char P, BiTree *E1, BiTree E2)
{
    BiTree E;
    E = (BiTree)malloc(sizeof(BiTNode));
    E -> data.tag = CHAR;
    E -> data.c = P;
    E -> lchild = *E1;
    E -> rchild = E2;
    (*E1) = E;
    printf("\n表达式E复合成功！其表达式变为：\n");
    WriteExpr(E);
}

//输出选择菜单
int menu()
{
    printf("1.输入前缀表达式\n");
    printf("2.输出表达式的中缀表示式\n"); 
    printf("3.对变量赋值\n");
    printf("4.计算表达式的值\n");
    printf("5.构造一个新的复合表达式\n");
    printf("0.退出\n\n");
    printf("请输入你的选择: "); 
    int choice = -1;
    scanf("%d%*c", &choice);
    return choice;
}

int main()
{
    BiTree E,newE;  //二叉树 
    char EXPR[81];  //前缀表达式 
    int flag = ERROR, flag2 = ERROR;   //标记表达式是否赋值成功, OK为成功, ERROR为失败
    char V; //要赋值的变量 
    char P; //合并的操作符 
    while(1)
    {
        switch(menu())
        {
            case 1:
         	  	do{
                    printf("请输入正确的前缀表达式: ");
                    flag = ReadExpr(&E, EXPR);
                    if(flag == OK)
                        printf("表达式构造成功.\n\n");
                    else
                    {
                        printf("表达式构造失败.\n");
                        printf("请输入正确的前缀表达式: ");
                    }
                }while(flag == ERROR);
                if(flag == OK)
                {
                    printf("前缀表达式的中缀表示式为： ");
                    WriteExpr(E);
                    printf("\n\n");
                }
                break;
            case 2:
                if(flag == OK) 
                {
                    printf("前缀表达式的中缀表示式为： ");
                    WriteExpr(E);
                    printf("\n");
                }
                else
                    printf("表达式还没有构造, 请先构造表达式.\n");
                break;
            case 3:
                if(flag == OK)
                {
                    int Assign_tag = ERROR;//是否赋值成功的标记 
                    char ch;//保存要赋值的变量 
                    int n;//保存要赋的值 
                    printf("请输入要赋值的变量名: "); 
                    ch = getchar();
                    printf("\n要赋值为: "); 
                    scanf("%d", &n);
                    Assign(&E, ch, n, &Assign_tag);
                    if(Assign_tag == OK)
                    {
                        printf("赋值成功!\n");
                        printf("赋值后表达式为：");
                        WriteExpr(E);
                        printf("\n");
                    }
                    else
                        printf("表达式里没有 %c 这个变量!\n", ch);
                }
                else
                    printf("表达式还没有构造, 请先构造表达式.\n");
                break;
            case 4:
                if(flag == OK)
                {
                    int chk = ERROR;
                    chk = Check(E);
                    if(chk == OK)//检查表达式里是否还有未赋值的变量 
                    {
                        WriteExpr(E);
                        printf("=%d\n", Value(E));
                    }
                    else
                    {
                        printf("表达式里还有未赋值变量！\n\n");
                    } 
                }
                break;
            case 5:
                if(flag == OK)
                {
                    do{
                        printf("请输入新的表达式: ");
                        
                        flag2 = ReadExpr(&newE, EXPR);
                        
                        if(flag2)
                            printf("表达式2构造成功.\n");
                        else
                        {
                            printf("表达式2构造失败.\n");
                            printf("请输入正确的前缀表达式.\n");
                        }
                    }while(flag2 == ERROR);
                    
                    printf("前缀表达式2的中缀表示式为： ");
                    WriteExpr(newE);
                    printf("\n\n");
                    
                    do{
                        printf("请输入运算符: ");
                        P = getchar();
                    }while(!isoperator(P));
                     
                    CompoundExpr(P, &E, newE);
                    
                    printf("复合的前缀表达式的中缀表示式为： ");
                    WriteExpr(E);
                    printf("\n\n");
                }
                break;
            case 0:
                printf("\n请按任意键退出！\n");
                getch();
                exit(0);
            default:
                printf("\n输入有误！请按任意键回到主菜单重新选择！\n");
				getch();
                break;
        }
    }
}
