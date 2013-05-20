#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

/* 状态码常量定义 */
#define FINISHED	0	/* 表示线程处于终止态或者TCB是空白状态 */
#define RUNNING	1	/* 表示线程处于运行态 */
#define READY	2	/* 表示线程处于就绪态 */
#define BLOCKED	3	/* 表示线程处于阻塞态 */

#define NTCB	100	/* NTCB是系统允许的最多任务数 */
#define SIZE	10		/* 数组大小 */

struct TCB{
	unsigned char *stack;	/* 线程堆栈的起始位置 */
	unsigned ss;				/* 堆栈段址 */
	unsigned sp;				/* 堆栈指针 */
	char state;				/* 线程状态，取值可以是FINISHED, RUNNING, READY, BLOCKED */
	char name[SIZE];			/* 线程的外部标识符 */
} tcb[NTCB];

void f1(void);
void f2(void);

typedef int (far *codeptr)(void);	/* 定义了一个函数指针类型 */
int create(char *name, codeptr code, int stck);
void destroy(int id);
void over(void);

int current = -1;

struct int_regs{
	unsigned bp, di, si, ds, es, dx, cx, bx, ax, ip, cs, flags, off, seg;
};

int main()
{
	
}

void f1(void)
{
	int i, j, k;
	for(i = 0; i < 40; i++)
		putchar('a');
	/* 延时 */
	for(j = 0; j < 10000; j++)
		for(k = 0; k < 10000; k++)
			;
}

void f2(void)
{
	int i, j, k;
	for(i = 0; i < 30; i++)
		putchar('b');
	/* 延时 */
	for(j = 0; j < 10000; j++)
		for(k = 0; k < 10000; k++)
			;
}

int create(char *name, codeptr code, int stck)
{
	int i, id = -1;
	unsigned char *ptr;
	struct int_regs far *r;
	
	for(i = 0; i < NTCB; i++)
		if(tcb[i].state == FINISHED){
				id = i;
				break;
		}
	
	if(id == -1)	/* 创建新线程失败 */
		return -1;
	
	tcb[id].stack = (unsigned char *)malloc(stck);
	r = (struct int_regs *)(tcb[id].stack + stck);
	r--;
	tcb[id].ss = FP_SEG(r);
	tcb[id].sp = FP_OFF(r);
	r->cs = FP_SEG(code);
	r->ip = FP_OFF(code);
	r->ds = _DS;
	r->es = _DS;
	r->flags = 0x200;
	r->seg = FP_SEG(over);
	r->off = FP_OFF(over);
	tcb[id].state = READY;
	strcpy(tcb[id].name, name);
	
	return id;
}

void destroy(int id)
{
	free(tcb[id].stack);
	tcb[id].stack = NULL;
	tcb[id].state = FINISHED;
	strcpy(tcb[id].name, "\0");
}

void interrupt swtch(void)
{
	int loop = 0;
	disable();
	
	tcb[current].ss = _SS;
	tcb[current].sp = _SP;
	
	if(tcb[current].state==RUNNING)
		tcb[current].state=READY;
	
	if(++current == NTCB)
		current = 0;
	while(tcb[current].state != READY && loop++ < NTCB - 1){
		current++;
		if(current == NTCB)
			current = 0;
	}
	
	if(tcb[current].state != READY)
		current = 0;
	
	_SS = tcb[current].ss;
	_SP = tcb[current].sp;
	tcb[current].state = RUNNING;
	timecount = 0;
	
	enabel();
}

void over(void)
{
	destroy(current);
	swtch();
}

