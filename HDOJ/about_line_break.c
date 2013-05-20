#include "stdio.h"
#include "conio.h"
void main()
{
    char i;
    i=getch();
    printf("%d\n",i);
    while(i=='\r'){
    	printf("pig\n");
    	scanf("%c",&i);
    	printf("%d\n",i);
    }
    getch();
}