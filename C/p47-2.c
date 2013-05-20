//Greater commo divisor program.
#include<stdio.h>

//求最大公约数的函数 
int gcd(int m,int n)    //m是被除数,n是除数. 
{
    int r;
    
    while(n!=0)
    {
        r=m%n;      //r保存余数 
        m=n;        //除数变被除数 
        n=r;        //余数变除数 
    }    
    return m;
}

//求最小公倍数 
int lcd(int m, int n)
{
    return m*n/gcd(m,n);    
} 

//交换两个数的值 
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;    
} 

int main(void)
{
    int x, y, g;
    
        printf("\nEnter two integers: ");
        scanf("%d%d",&x,&y);
        
        if(x < y)
            swap(&x,&y);
            
        printf("%d和%d的最大公约数是: %d\n",x,y,gcd(x,y));
        printf("%d和%d的最小公倍数是: %d\n",x,y,lcd(x,y));
    
    system("pause");
    return 0;
}
