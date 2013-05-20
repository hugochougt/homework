
typedef struct
{
	ElemType stack[STACK_INIT_SIZE];
	int top0, top1;
}DStack;

Status inistack(DStack &tws)
{
	tws -> top0 = -1;
	tws -> top1 = STACK_INIY_SIZE;
	return OK;
}

Status push(DStack &tws, int i, ElemType x)
{
	if(tws -> top0 + 1 == tws -> top1)
	{
		return ERROR;
	}
	switch(i)
	{
		case 0:
			tws -> top0++;
			tws -> stack[tws -> top0] = x;
		case 1:
			tws -> top1--;
			tws -> stack[tws -> top1] = x;
	}
	return OK;
}

Status pop(DStack &tws, int i, ElemType &x)
{
	switch(i)
	{
		case 0: 
			if(tws -> top0 == -1)
				return ERROR;
			*x = tws -> stack[tws -> top0];
			tws -> top0--;
			return OK;
		case 1:
			if(tws -> top1 == STACK_INIY_SIZE)
				return ERROR;
			*x = tws -> stack[tws -> top1];
			tws -> top1++;
			return OK;
	}
}