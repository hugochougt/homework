/******用链表实现队列.cpp******/
#include <iostream>
#include <string>
using namespace std;

class Information
{
private:
    string sInfoName;
    string sDate;   //数据
public:
    Information(string sInfoName) //从键盘读数据信息
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
class QueClass    //定义一个QueClass类
{
private:
    Node *FRONT;   //队列头
    Node *REAR;    //队列尾
public:
    QueClass()    //构造符函数
    {
        FRONT=NULL;
        REAR=NULL;
    }
    ~QueClass()    //析造符函数
    {
        while(FRONT!=NULL)
        {
            FRONT=FRONT->NEXT;
            delete FRONT;
        }
    }
    void AddNode(string str); //增加节点
    void DeleNode();    //删除当前节点
    void Traverse();
};
void QueClass::AddNode(string str)//增加节点到队列头
{
    Node *n=new Node(str);
    if(FRONT==NULL)    //创建队列的第一个节点
    {
        n->NEXT=NULL;
        FRONT=n;
        REAR=n;     //FRONT和REAR指向唯一的n
        return;     //函数返回,不再向下执行
    }
    else
    {
        REAR->NEXT=n;   //原REAR的NEXT指向n
        REAR=n;     //n作为新的REAR
    }
}
void QueClass::DeleNode() //删除队列头节点
{
    if(FRONT==NULL)
    {
        cout << "\n   队列不存在!!! " << endl;
        return; 
    }
    Node *TEMP;
    TEMP=FRONT;
    FRONT=FRONT->NEXT;
    delete TEMP;
}
void QueClass::Traverse() //遍历队列(浏览所有节点信息)
{
    if(FRONT==NULL)
    {
        cout << "\n   队列不存在!!! " << endl;
    }
    else
    {
        Node *TEMP;
        for(TEMP=FRONT;TEMP!=NULL;TEMP=TEMP->NEXT)
        {      //循环显示所有节点信息
            cout<<TEMP->Disp_Node()<<endl; //显示节点标示
        }
    }
}
int main()      //主函数
{
    QueClass QueObj;
    string data;
    cout << "\n **************《队列操作》************** "<< endl;
    char cCmd;
    do
    {
        cout << "\n   加入(A) 删除(D) 浏览(T) 退出(E): ";
        cin >> cCmd;
        switch(cCmd)
        {
            case 'A':
            case 'a':
            {
                cout<<"\n   输入名称 : ";
                cin >> data;
                QueObj.AddNode(data);
                break;
            }
            case 'D':
            case 'd':
            {
                QueObj.DeleNode();
                break;
            }
            case 'T':
            case 't':
            {
                QueObj.Traverse();
                break;
            }
            case 'E':
            case 'e':
            {
                cout<<"\n *************《操作完毕》************* \n"; 
                break; 
            }
            default:
                cout << "\n   输入错误,重新选择菜单 : \n";
        }
    }while(cCmd!='E' && cCmd!='e');
    return 0;
}
