//题7. 约瑟夫问题

#include<stdio.h>
#include<stdlib.h>

typedef struct LNode
{
	int num;   //编号 
	int code;  //密码 
	struct LNode *next;
}LNode;

void Josephus(struct LNode *tail, int n, int m)
{
    struct LNode *head;     //头结点 
    struct LNode *p, *q;    //辅助节点 
    int i, j;
    if(n < 1)  //人数异常, 退出程序 
	{
        printf("Number error!\n");
		exit(1);   
    }
    
    if(1 == n)
    {
        printf("1\n");
        exit(0);
    }
    
    //当 n >= 2 时 
    
	head = (LNode *)malloc(sizeof(LNode));
	p = head;
	p -> num = 1;
	scanf("%d", &(p -> code));  //输入第一个密码 

	for(i = 2; i <= n; i++)
	{
		q = (LNode *)malloc(sizeof(LNode));
		p -> next = q;
		q -> num = i;     //写入编号 
		scanf("%d", &(q -> code)); //输入其余的密码 
		p = q;    //p指向已建链表的最后一个节点 
	}
	
	tail = p;
	tail -> next = head;    //建立循环链表 
	
	p = tail;
	   
	for(i = 1 ; i <= n; i++)
	{
		for(j = 1; j < m; j++)  //p定位在出列者的前一人 
		{
			p = p -> next;
		}
		    
		q = p -> next;    //q指向出列者
             
		printf("%d", q -> num); //输出出列者的编号 
		printf("%c", i < n ? ' ' : '\n');
		    
		m = q -> code;    //更新报数上限 
		p -> next = q -> next;    //p指向出列者的下一人
		    
		free(q); //删除出列者节点 
	}
}

int main()
{
    struct LNode *tail;     //尾节点 
    
    int n;  //人数 
    int m;  //报数上限 
    
    printf("Input the number of people: ");
	scanf("%d", &n);
    
    printf("Input the first code: ");
	scanf("%d", &m);
    
    Josephus(tail, n, m);
	
	return 0;
}
