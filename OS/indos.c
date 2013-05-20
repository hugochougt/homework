/* indos.c -- Functions to manage DOS flags */
#include<stdlib.h>
#include<dos.h>

#define GET_INDOS 0x34
#define GET_CRIT_ERR 0x5d06

char far *indos_ptr = 0;	/* 该指针变量存放INDOS标志的地址 */
char far *crit_err_ptr = 0;	/* 该指针变量存放严重错误标志的地址 */

void InitDos(void);
int DosBusy(void);

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
		indosx(&regs, &regs, &segregs);
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