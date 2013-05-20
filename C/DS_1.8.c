//Data Structure 1.8

#include<stdio.h>

void Q_1(int n)
{
    int i = 1, k = 0;
    while(i <= n - 1)
    {
        k++;
        i++;
    }
    printf("Q_1: %d\n\n",k);
}

void Q_2(int n)
{
    int i = 1, k = 0;
    do{
        k++;
        i++;
    }while(i <= n - 1);
    printf("Q_2: %d\n\n",k);
}

void Q_3(int n)
{
    int i = 1, k = 0;
    while(i <= n - 1)
    {
        i++;
        k++;
    }
    printf("Q_3: %d\n\n",k);
}

void Q_4(int n)
{
    int k = 0;
    int i,j;
    for(i = 1; i <= n; i++)
        for(j = i; j <= n; j++)
            k++;
            
    printf("Q_4: %d\n\n",k);
}

void Q_5(int n)
{
    int i, j, k, c=0;
    for(i = 1; i <= n; i++)
        for(j = 1; j <= i; j++)
            for(k = 1; k <= j; k++)
                c++;
    printf("Q_5: %d\n\n",c);
}

void Q_6(int n)
{
    int i = 1, j = 0, c = 0;
    while(i + j <= n)
    {
        c++;
        if(i > j)
            j++;
        else
            i++;
    }
    printf("Q_6: %d\n\n",c);
}

void Q_7(int n)
{
    int y = 0, c = 0;
    while(n >= (y + 1) * (y + 1))
    {
        c++;
        y++;
    }
    printf("Q_7: %d\n\n",c);
}

void Q_8()
{
    int x = 91, y = 100, c = 0;
    while(y > 0)
    {
        c++;
        if(x > 100)
        {
            x -= 10;
            y--;
        }
        else
            x++;
    }
    printf("Q_8: %d\n\n",c);
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        Q_1(n);
        Q_2(n);
        Q_3(n);
        Q_4(n);
        Q_5(n);
        Q_6(n);
        Q_7(n);
        Q_8();
    }
    return 0;
}
