
typedef struct CirQueue
{
	ElemType data;
	CirQueue *next;
}CirQueue;

Status initQueue(CirQueue &CQ)
{
	CQ = (cirQueue *)malloc(sizeof(CirQueue));
	CQ -> next = CQ;
}

Status EnCirQueue(CirQueue &CQ, ElemType x)
{
	p = (CirQueue *)malloc(sizeof(CirQueue));
	p -> data = x;
	p -> next = CQ -> next;
	CQ ->next = p;
	CQ = p;
	return Ok;
}

Status DeCirQueue(CirQueue &CQ, ElemType &x)
{
	if(CQ == CQ -> next)
		return INFEASIBLE;
	p = CQ -> next;
	*x = p -> data;
	CQ -> next = p -> next;
	free(p);
	return OK;
}