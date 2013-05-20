#include <stdio.h>
int main()
{
    int n;
    int fibo(int x);
    printf("Enter n: ");
    scanf("%d",&n);
    printf("\nFibonacci sequence:\n");
    fibo(n);
    getch();
    return 0;
}
int fibo(int x)
{
    static int a,b;
    int c;
    if(x<2)
    {
        a = 0;
        b = 1;    
    }
    else
    {
        fibo(x-1);
        c = b;
        b = a + b;
        a = c;    
    }
    printf("%d ",a);
}
