//Array implementation of a stack
#include <stdio.h>

int stack[20], item, i, n = 10;
int top = -1;
void insert(int );
void dele();
void display();

int main() 
{
    while(1)
    {
        printf("Array implementation of a stack\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&i);
        switch(i)
        {
            case 1:
                    printf("Instertion\n");
                    printf("Enter item: ");
                    scanf("%d",&item);
                    insert(item);
                    break;
            case 2:
                    printf("Deletion\n");
                    dele();
                    break;
            case 3:
                    display();
                    break;
            case 4:exit(1);
        }
    }
    return 0;
}

void insert(int it)
{
    if(top >= n)
    {
        printf("Stack full.\n");
        return ;
    }
    top++;
    stack[top] = it;
    return ;
}

void dele()
{
    if(top < 0)
    {
        printf("Stack empty.\n");
        return ;    
    }    
    item = stack[top];
    printf("Deleted item is %d\n",item);
    top--;
    return ;
}

void display()
{
    int i;
    for(i = 0; i <= top; i++)
    {
        printf("%d ",stack[i]);    
    }
    printf("\n");
    return ;
}
