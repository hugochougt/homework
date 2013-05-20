//Josephus
#include<iostream>
using namespace std;

typedef struct LNode
{
    int num;   //编号
    int code; //密码
    struct LNode *next;
}LNode;

void create(LNode *&tail, int m, int n)
{
    LNode *p, *q; //辅助节点
    LNode *head; //头结点
    if(n < 1) //人数异常, 退出程序
    {
        cout << "Number error!" << endl;
        system("pause");
        exit(1);  
    }
   
    if(n == 1)
    {
        cout << "1" << endl;
        system("pause");
        exit(0);
    }

    //当 n >= 2 时

    head = new LNode;
    p = head;
    p -> num = 1;
    cin >> p ->code; //输入第一个密码

    for(int i = 2; i <= n; i++)
    {
        q = new LNode;
        p -> next = q;
        q -> num = i;     //写入编号
        cin >> q -> code; //输入其余的密码
        p = q;    //p指向已建链表的最后一个节点
    }

    tail = p;
    tail -> next = head;    //建立循环链表
}

void run(LNode *&tail, int m, int n)
{
    LNode *p, *q; //辅助节点
    p = tail;
   
    for(int i = 1 ; i <= n; i++)
    {
        for(int j = 1; j < m; j++) //p定位在出列者的前一人
        {
            p = p -> next;
        }
     
        q = p -> next;    //q指向出列者
            
        cout << q -> num; //输出出列者的编号
        i < n ? cout << ' ' : cout << endl;
     
        m = q -> code;    //更新报数上限
        p -> next = q -> next;    //p指向出列者的下一人
     
        delete q; //删除出列者节点
    }
}

int main()
{
    LNode *tt; //尾节点

    int m; //报数上限
    int n; //人数

    cout << "Input the number of people: ";
    cin >> n;
   
    cout << "Input the first code: ";
    cin >> m;

    create(tt, m, n);
    run(tt, m, n);

    return 0;
}
