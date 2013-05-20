 Statue EnCirQueue(CirQueue &CQ, ElemType x)
 {
	if(CQ.length == MAXSIZE)
		return OVERFLOW;
	CQ.rear = (CQ.rear + 1) % MAXSIZE;
	CQ.base[CQ.rear] = x;
	CQ.length++;
	return OK;
 }

 Status DeCirQueue(CirQueue &CQ, ElemType &x)
 {
	if(CQ.lenth == 0)
		return INFEASIBLE;
	head = (CQ.rear + MAXSIZE - CQ.length + 1) % MAXSIZE;
	*x = CQ.base[head];
	CQ.length--;
	return OK;
 }