/******用链表实现栈.cpp******/
#include <iostream>
#include <string>
using namespace std;

class Information
{
private:
    string sInfoName;
    string sDate;   //数据
public:
    Information(string sInfoName)   //从键盘读数据信息
    {
        this->sInfoName=sInfoName;
        cout<<"   输入数据 : ";
        cin>>sDate;
    }
    string Disp_Info() //显示节点数据信息
    {
        return sDate;
    }
};

class Node
{
private:
    string sNodeName; //节点标示名称
    Information INFO; //节点数据信息(Information) 
public:
    Node *NEXT;    //指向下一节点的节点指针(NEXT) 
    Node(string sNodeName,Node *NEXT=NULL):INFO(sNodeName)
    {
        this->sNodeName=sNodeName;
        this->NEXT=NEXT;
    }
    string Disp_Node() //显示节点数据信息
    {
        return sNodeName;
    }
};
class Stack     //定义一个Stack类
{
private:
    Node *TOP;    //栈顶
public:
    Stack()     //构造符函数
    {
        TOP=NULL;
    }
    ~Stack()    //析造符函数
    {
        while(TOP!=NULL)
        {
            TOP=TOP->NEXT;
            delete TOP;
        }
    }
    void Push(string str); //增加节点
    void Pop();     //删除当前节点
    void Traverse();
};
void Stack::Push(string str)//增加节点到栈顶
{
    Node *n=new Node(str);
    if(TOP==NULL)    //创建栈的第一个节点
    {
        n->NEXT=NULL;
        TOP=n;
        return;     //函数返回,不再向下执行
    }
    else
    {
        n->NEXT=TOP;
        TOP=n;
    }
}
void Stack::Pop()    //删除栈顶节点
{
    if(TOP==NULL)
    {
        cout << "\n   栈不存在!!! " << endl;
        return; 
    }
    Node *TEMP;
    TEMP=TOP;
    TOP=TOP->NEXT;
    delete TEMP;
}
void Stack::Traverse()   //遍历栈(浏览所有节点信息)
{
    if(TOP==NULL)
    {
        cout << "\n   栈不存在!!! " << endl;
    }
    else
    {
        Node *TEMP;
        for(TEMP=TOP;TEMP!=NULL;TEMP=TEMP->NEXT)
        {      //循环显示所有节点信息
            cout<<TEMP->Disp_Node()<<endl; //显示节点标示
        }
    }
}
int main()      //主函数
{
    Stack stObj;
    string data;
    cout << "\n **************《栈操作》************** "<< endl;
    char cCmd;
    do
    {
        cout << "\n   加入(A) 抹去(D) 浏览(T) 退出(E): ";
        cin >> cCmd;
        switch(cCmd)
        {
            case 'A':
            case 'a':
            {
                cout<<"\n   输入姓名 : ";
                cin >> data;
                stObj.Push(data);
                break;
            }
            case 'D':
            case 'd':
            {
                stObj.Pop();
                break;
            }
            case 'T':
            case 't':
            {
                stObj.Traverse();
                break;
                }
            case 'E':
            case 'e':
            {
                cout<<"\n *************《操作完毕》************* \n"; 
                break; 
            }
            default:
                cout << "\n   输入错误,重新选择菜单 : ";
        }
    }while(cCmd!='E' && cCmd!='e');
    return 0;
}
