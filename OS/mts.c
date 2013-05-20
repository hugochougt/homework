#include <alloc.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>

/* 状态码常量定义 */
#define FINISHED	0	/* 表示线程处于终止态或者TCB是空白状态 */
#define RUNNING	1	/* 表示线程处于运行态 */
#define READY	2	/* 表示线程处于就绪态 */
#define BLOCKED	3	/* 表示线程处于阻塞态 */

#define NTCB	10	/* NTCB是系统允许的最多任务数 */
#define NTEXT	20		/* 文本大小 */
#define NBUF	5		/* 缓冲区大小 */
#define NSTACK 1024		/* 私有栈大小 */

#define GET_INDOS 0x34
#define GET_CRIT_ERR 0x5d06

char far *indos_ptr = 0;	/* 该指针变量存放INDOS标志的地址 */
char far *crit_err_ptr = 0;	/* 该指针变量存放严重错误标志的地址 */

int timecount = 0;
int TL;					/* time slice时间片 */
int current = -1;		/* 当前进程的tcb下标 */
int n = 0;

typedef int (far *codeptr)(void);	/* 定义一个函数指针类型 */
void interrupt(*old_int8)(void);

/* 记录型信号量 */
typedef struct{
		int value;
		struct TCB *wq;
	}semaphore;

semaphore mutex = {1, NULL};	
semaphore mutexfb = {1, NULL};	/* 缓冲区互斥信号量 */
semaphore sfb = {NBUF, NULL};	/* 计算信号量 */
semaphore empty = {NBUF, NULL};
semaphore full = {0, NULL};

/* 消息缓冲区 */
struct buffer{
	int id;
	int size;
	char text[NTEXT];
	struct buffer *next;
}buf[NBUF], *freebuf;

struct TCB{
	unsigned char *stack;	/* 线程堆栈的起始位置 */
	unsigned ss;				/* 堆栈段址 */
	unsigned sp;				/* 堆栈指针 */
	char state;				/* 线程状态，取值可以是FINISHED, RUNNING, READY, BLOCKED */
	char name[NTEXT];		/* 线程的外部标识符 */
	struct buffer *mq;		/* 接收线程的消息队列首指针 */
	semaphore mutex;			/* 接收线程的消息队列的互斥信号量 */
	semaphore sm;			/* 接收线程的消息队列的计数信号量，用于实现同步 */
	struct TCB *next;
} tcb[NTCB];

struct int_regs{
	unsigned bp, di, si, ds, es, dx, cx, bx, ax, ip, cs, flags, off, seg;
};

int intbuf[NBUF], buftemp;
int in = 0, out = 0;

void over();
void destroy(int id);
void wait(semaphore *sem);
void signal(semaphore *sem);
void block(struct TCB **qp);
void wakeupFirst(struct TCB **qp);
void send(char *receiver, char *a, int size);
int receive(char *sender, char *b);

/* InitDos()函数：功能是获得INDOS标志地址和严重错误标志的地址 */
void InitDos(void)
{
	union REGS regs;
	struct SREGS segregs;
	
	/* 获得INDOS标志的地址 */
	regs.h.ah = GET_INDOS;
	/* intdosx(): Turbo C的库函数，其功能是调用DOS的INT21H中断 */
	intdosx(&regs, &regs, &segregs);
	/* MK_FP(): 不是一个函数，只是一个宏 */
	/* 其功能是做段基址加上偏移地址的运算，也就是取实际地址。 */
	indos_ptr = MK_FP(segregs.es, regs.x.bx);
	
	/* 获得严重错误标志的地址 */
	/* 代码中用到的_osmajor、_osminor是Turbo C的全程变量， 其中前者为DOS版本号的主要部分，后者为版本号的次要部分。 */
	if(_osmajor < 3)
		crit_err_ptr = indos_ptr + 1;
	else if(_osmajor == 3 && _osminor == 0)
		crit_err_ptr = indos_ptr - 1;
	else
	{
		regs.x.ax = GET_CRIT_ERR;
		intdosx(&regs, &regs, &segregs);
		crit_err_ptr = MK_FP(segregs.ds, regs.x.si);
	}
}

/* DosBusy(): 函数功能是获得Indos标志及严重错误标志的值，判断是否dos忙； */
/* 如果返回值是1，表示dos忙； */
/* 如果返回值是0，表示dos不忙； */
/* 如果返回值是-1，表示还没有调用InitDos() */
int DosBusy(void)
{
	if(indos_ptr && crit_err_ptr)
		return (*indos_ptr || *crit_err_ptr);
	else
		return -1;	/* InitDos() hasn't been called */
}

/* 初始化tcb */
void initTCB()
{
	int i;
	for(i = 0; i < NTCB; i++){
		tcb[i].name[0] = '\0';
		tcb[i].stack = NULL;
		tcb[i].state = FINISHED;
		tcb[i].mq = NULL;
		tcb[i].mutex.value = 1;
		tcb[i].mutex.wq = NULL;
		tcb[i].sm.value = 0;
		tcb[i].sm.wq = NULL;
		tcb[i].next = NULL;
	}
}

void f1(void)
{
	long i,j,k;
	for(i=0;i<1000;i++){
		putchar('a');
		for(j=0;j<1000;j++)
			for(k=0;k<100;k++);
	}
}

void f2(void)
{
	long i,j,k;
	for(i=0;i<100;i++){
		putchar('b');
		for(j=0;j<1000;j++)
			for(k=0;k<100;k++);
	}
}

void f3(void)
{
	long i,j,k;
	for(i=0;i<1000;i++){
		putchar('c');
		for(j=0;j<1000;j++)
			for(k=0;k<100;k++);
	}
}

void f4()
{
	int i;
	for(i = 0; i < 10; i++){
		wait(&mutex);
		n++;
		printf(" %d", n);
		signal(&mutex);
		sleep(1);
	}
}

void f5()
{
	int i;
	for(i = 0; i < 5; i++){
		wait(&mutex);
		n--;
		printf(" %d ", n);
		signal(&mutex);
		sleep(1);
	}
}

void prdc()
{
	int tmp, i;
	for(i = 1; i <= 10; i++)
	{
		tmp = i * i;
		printf("prdc %d\n", tmp);
		wait(&empty);
		wait(&mutex);
		intbuf[in] = tmp;
		in = (in + 1) % NBUF;
		/*printf("in: %d\n", in);*/
		signal(&mutex);
		signal(&full);
		
	}
}

void cnsm()
{
	int tmp, i;
	for(i = 1; i <= 10; i++)
	{
		wait(&full);
		wait(&mutex);
		tmp = intbuf[out];
		out = (out + 1) % NBUF;
		/*printf("out: %d\n", out);*/
		signal(&mutex);
		signal(&empty);
		printf("Out %d: %d\n", i, tmp);
		sleep(2);
	}
}

void sender(void)
{
	int i,j;
	char a[10];
loop:
	for(i=0;i<10;i++){
		strcpy(a,"message");
		a[7]='0'+n;
		a[8]=0;
		send("receiver",a,strlen(a));
		printf("sender:Message \"%s\"  has been sent\n",a);
		n++;
	}
	receive("receiver",a);
	if (strcmp(a,"ok")!=0){
		printf("Not be committed,Message should be resended!\n");/*接收进程没确认,需重新发送消息*/
		goto loop;
	}else
		printf("Committed,Communication is finished!\n");/*发送者得到接收者的确认,通信结束*/
}

void receiver(void)
{
	int i,j,size;
	char b[10];
	for(i=0;i<10;i++){
		b[0]=0;
		while((size=receive("sender",b))==-1);
		printf("receiver: Message is received--");
		for(j=0;j<size;j++)
			putchar(b[j]);
		printf("\n");
	}
	strcpy(b,"ok");
	send("sender",b,3);/* 发送确认消息 */
}

int create(char *name, codeptr code, int stck)
{
	struct int_regs far *r;
	int i, id = -1;
	
	for(i = 0; i < NTCB; i++){
		if(tcb[i].state == FINISHED){
			id = i;
			break;
		}
	}
	
	if(id == -1)
		return -1;
	disable();
	
	tcb[id].stack = (unsigned char *)malloc(stck);
	r = (struct int_regs *)(tcb[id].stack + stck);
	r--;
	tcb[id].ss=FP_SEG(r);
	tcb[id].sp=FP_OFF(r);
	r->cs = FP_SEG(code);
	r->ip = FP_OFF(code);
	r->es = _DS;
	r->ds = _DS;
	r->flags = 0x200;
	r->seg = FP_SEG(over);
	r->off = FP_OFF(over);
	tcb[id].state = READY;
	strcpy(tcb[id].name, name);
	enable();
}

void interrupt swtch()
{
	int loop = 0;
	disable();
	
	tcb[current].ss = _SS;
	tcb[current].sp = _SP;
	
	if(tcb[current].state == RUNNING)
		tcb[current].state = READY;
	
	while(tcb[++current].state != READY && loop++ < NTCB - 1)
		if(current == NTCB)
			current = 0;
	
	if(tcb[current].state != READY)
		current = 0;
	_SS = tcb[current].ss;
	_SP = tcb[current].sp;
	
	tcb[current].state = RUNNING;
	
	timecount = 0;
		
	enable();
}

void destroy(int id)
{
	disable();
	free(tcb[id].stack);
	tcb[id].stack = NULL;
	tcb[id].state = FINISHED;
	printf("\nProcess %s terminated\n", tcb[id].name);
	tcb[id].name[0] = '\0';
	enable();
}

void over()
{
	destroy(current);
	swtch();
}

int finished()
{
	int i;
	for(i = 1; i < NTCB; i++)
		if(tcb[i].state != FINISHED)
			return 0;
	return 1;
}

void free_all(void)
{
	int i;

	for(i=0;i<NTCB;i++){
		if(tcb[i].stack){
			tcb[i].name[0]='\0';
			tcb[i].state=FINISHED;
			free(tcb[i].stack);
			tcb[i].stack=NULL;
		}
	}
}

void interrupt new_int8()
{
	(*old_int8)();
	timecount++;
	if(timecount < TL)
		return ;
	if(DosBusy())
		return ;
	swtch();
}

void wait(semaphore *sem)
{
	struct TCB **qp;
	disable();
	sem->value--;
	if(sem->value < 0){
		qp = &(sem->wq);
		block(qp);
	}
	enable();
}

void signal(semaphore *sem)
{
	struct TCB **qp;
	disable();
	qp = &(sem->wq);
	sem->value++;
	if(sem->value <= 0){
		wakeupFirst(qp);
	}
	enable();
}

void block(struct TCB **qp)
{
	int id;
	struct TCB *tcbtmp;
	
	id = current;
	tcb[id].state = BLOCKED;
	
	if((*qp) == NULL)
		(*qp) = &tcb[id];
	else{
		tcbtmp = *qp;
		while(tcbtmp->next != NULL)
			tcbtmp = tcbtmp->next;
		tcbtmp->next = &tcb[id];
	}
	
	tcb[id].next = NULL;
	swtch();
}

void wakeupFirst(struct TCB **qp)
{
	struct TCB *tcbtmp;
	
	if((*qp) == NULL)
		return ;
	
	tcbtmp = *qp;
	*qp = (*qp)->next;
	tcbtmp->state = READY;
	tcbtmp->next = NULL;
}

void initBuf()
{
	int i;
	for(i = 0; i < NBUF - 1; i++){
		buf[i].next = &buf[i+1];
	}
	buf[i].next = NULL;
	freebuf = &buf[0];
}

struct buffer *getbuf()
{
	struct buffer *buff;
	buff = freebuf;
	freebuf = freebuf->next;
	return buff;
}

void insert(struct buffer **mq, struct buffer *buff)
{
	struct buffer *temp;
	if(buff == NULL)
		return ;
	buff->next = NULL;
	if(*mq == NULL)
		*mq = buff;
	else
	{
		temp = *mq;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = buff;
	}
}

void send(char *receiver, char *a, int size)
{
	struct buffer *buff;
	int i, id = -1;
	
	disable();
	for(i = 0; i < NTCB; i++){
		if(strcmp(receiver, tcb[i].name) == 0){
			id = i;
			break;
		}
	}
	if(id == -1){
		printf("Error: Receiver not exist.\n");
		enable();
		return ;
	}
	wait(&sfb);
	wait(&mutexfb);
	buff = getbuf();
	signal(&mutexfb);
	
	buff->id = current;
	buff->size = size;
	buff->next = NULL;
	strcpy(buff->text, a);
	
	wait(&tcb[id].mutex);
	insert(&tcb[id].mq, buff);
	signal(&tcb[id].mutex);
	
	signal(&tcb[id].sm);
	enable();
}

struct buffer *remov(struct buffer **mq, int sender)
{
	struct buffer *buff, *p, *q;
	q = NULL;
	p = *mq;
	while((p->next != NULL) && (p->id != sender))
	{
		q = p;
		p = p->next;
	}
	if(p->id == sender){
		buff = p;
		if(q == NULL)
			*mq = buff->next;
		else
			q->next = buff->next;
		buff->next = NULL;
		return buff;
	}
	else
		return NULL;
}

int receive(char *sender, char *b)
{
	int i, id = -1;
	struct buffer *buff;
	disable();
	for(i = 0; i < NBUF; i++)
	{
		if(strcmp(sender, tcb[i].name) == 0){
			id = i;
			break;
		}
	}
	if(id == -1)
	{
		enable();
		return -1;
	}
	wait(&tcb[current].sm);
	wait(&tcb[current].mutex);
	buff = remov(&(tcb[current].mq), id);
	signal(&tcb[current].mutex);
	if(buff == NULL){
		signal(&tcb[current].sm);
		enable();
		return -1;
	}
	strcpy(b, buff->text);
	wait(&mutexfb);
	insert(&freebuf, buff);
	signal(&mutexfb);
	signal(&sfb);
	
	enable();
	
	return buff->size;
}

void main()
{
	int select = -1;
	
	InitDos();
	initTCB();
	
	old_int8 = getvect(8);
	strcpy(tcb[0].name, "main");
	tcb[0].state = RUNNING;
	current = 0;
	
	while(select != 0){
		do{
			clrscr();
			printf("0. Exit\n");
			printf("1. First come first serve\n");
			printf("2. Time slice\n");
			printf("3. Change TL, see what would change\n");
			printf("4. Exclusively assess\n");
			printf("5. Producer and consumer SYNC problem\n");
			printf("6. Message buffer communication\n");
			scanf("%d", &select);
		}while(select < 0 || select > 7);

		switch(select){
			case 1:
				create("f1", (codeptr)f1, NSTACK);
				create("f2", (codeptr)f2, NSTACK);
				clrscr();
				printf("\ncreate f1 and f2\n");
				printf("f1 prints 1000 a\n");
				printf("f2 prints 100 b\n");
				swtch();
				getch();
				break;
			case 2:
				TL = 1;
				printf("Time slice = 1\n\n");
				getch();
				create("f1", (codeptr)f1, NSTACK);
				create("f2", (codeptr)f2, NSTACK);
				create("f3", (codeptr)f3, NSTACK);
				clrscr();
				printf("\ncreate f1, f2, f3\n");
				printf("f1 prints 1000 a\n");
				printf("f2 prints 100 b\n");
				printf("f3 prints 1000 c\n");
				setvect(8, new_int8);
				swtch();
				getch();
				break;
			case 3:
				printf("Enter new time slice: ");
				scanf("%d", &TL);
				printf("Time slice = %d\n\n", TL);
				getch();
				create("f1", (codeptr)f1, NSTACK);
				create("f2", (codeptr)f2, NSTACK);
				create("f3", (codeptr)f3, NSTACK);
				clrscr();
				printf("\ncreate f1, f2, f3\n");
				printf("f1 prints 1000 a\n");
				printf("f2 prints 100 b\n");
				printf("f3 prints 1000 c\n");
				setvect(8, new_int8);
				swtch();
				getch();
				break;
			case 4:
				n = 0;
				TL = 1;
				create("f4", (codeptr)f4, NSTACK);
				create("f5", (codeptr)f5, NSTACK);
				printf("\ncreate f4, f5\n");
				printf("f4 increase n 1 each time\n");
				printf("f5 decrease n 1 each time\n");
				setvect(8, new_int8);
				swtch();
				getch();
				break;
			case 5:
				TL = 4;
			
				create("prdc", (codeptr)prdc, NSTACK);
				create("cnsm", (codeptr)cnsm, NSTACK);
				printf("prdc\n");
				printf("cnsm\n");
				getch();
				setvect(8, new_int8);
				swtch();
				getch();
				break;
			case 6:
				initBuf();
				create("sender",(codeptr)sender,NSTACK);
				create("receiver",(codeptr)receiver,NSTACK);
				printf("sending\n");
				getch();
				TL = 1;
				setvect(8, new_int8);
				swtch();
				getch();
				break;
			default: select = 0;
		}
		while(!finished())
			;
		setvect(8, old_int8);
	}
	
	free_all();
	
	tcb[0].name[0] = '\0';
	tcb[0].state = FINISHED;
		
	printf("\nMulti task system terminated.\n");
	getch();
}
