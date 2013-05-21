//Josephus
//姓名: 周昌权  学号: 09051109  班级: 09051109   
#include<iostream>
#include<cstdio>
using namespace std;

typedef struct LNode
{
    int num;
    int code;
    struct LNode *next;
}LNode;

struct LNode *tail;		//尾结点
struct LNode *head;		//头结点
struct LNode *p, *q;	//辅助结点

int n;	//人数
int m;  //报数上限

//创建链表 
void create()
{
	cout << "Input the number of people: ";
    cin >> n;

	cout << "Input the first code: ";
	cin >> m;
    
	if(n < 1)	//人数数值异常
		exit(1);//退出程序

	head = new LNode;
	p = head;

    for(int i = 1; i < n; i++)
    {
        q = new LNode;
        p -> next = q;
		p = q;
    }

	tail = q;
	tail -> next = head;	//建立循环链表
	
    p = head;
	for(int i = 1; i <= n; i++)
	{
        p -> num = i;
        cin >> p -> code;	//输入密码
        p = p -> next;
    }
}

void run()
{
    p = tail;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j < m; j++)
		{
			p = p -> next;
		}
		q = p -> next;
		m = q -> code;
		cout << q -> num; //输出出列者的编号 
        i < n ? cout << ' ' : cout << endl;
		p -> next = q -> next;	//p指向出列者的下一个人

		delete q;
	}
}

int main(void)
{
	create();
	run();
	system("pause");
	return 0;
}