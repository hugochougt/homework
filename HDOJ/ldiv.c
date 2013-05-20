#include "stdio.h"
#include "stdlib.h"

typedef struct
{
	long quot;
	long rem;
}ldiv_t;

void main()
{
	ldiv_t lx;
	lx=ldiv(200000L,30000L);
	printf("200000 div 30000 = %ld remainder %ld\n",lx.quot,lx.rem);    
}