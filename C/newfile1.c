#include<stdio.h>
int main()
{
    void fun(int *x,int y);
    int k,a,y,b;
    scanf("%d%d",&a,&b);
    fun(&a,b);
    printf("a=%d, y=%d\n",a,y);
    system("pause");
    return 0;    
}

void fun(int *x, int y)
{
    *x = *x/10*10+y%10;    
    y = *x;
    printf("a=%d, y=%d\n",*x,y);
}
