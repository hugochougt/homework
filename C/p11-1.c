#include<stdio.h>
void main()
{
    int x,y,z;
    char a;
    scanf("%d%c%d",&x,&a,&y);
    switch(a)
    {
    case'+':z=x+y;break;
    case'-':z=x-y;break;
    case'*':z=x*y;break;
    case'/':z=x/y;break;
    }
    printf("%d%c%d=%d\n",x,a,y,z);
    system("pause");
}
    
