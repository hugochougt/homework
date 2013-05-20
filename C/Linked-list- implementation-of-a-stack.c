//Linked list implementation of a stack
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;    
};

struct node *top = NULL;

void push(int );
int pop();
void display();

int main() 
{
    int ch;
    int item;
    while(1)
    {
        printf("Linked list implementation of a stack\n");
        printf("1. Push...\n");
        printf("2. Pop...\n");
        printf("3. Display...\n");
        printf("4. Exit...\n");
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    printf("Push\n");
                    printf("Enter item: ");
                    scanf("%d",&item);
                    push(item);
                    break;
            case 2:
                    printf("Pop\n");
                    item = pop();
                    printf("Poped item: %d\n",item);
                    break;
            case 3:
                    display();
                    break;
            case 4:exit(1);
        }
    }
    return 0;
}

//Function used to add a new node to the stack
void push(int it)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp = NULL)
    {
        printf("Stack full.\n");
        return ;
    }
    temp -> data = it;
    temp -> link = top;
    top = temp;
}

//Function pops an item from the stack
int pop()
{
    struct node *temp = top;
    int item;
    if(top == NULL)
    {
        printf("Stack empty.\n");
        return NULL;    
    }
    item = temp -> data;
    top = top -> link;
    free(temp);
    return item;
}

//Function used to display the content of the stack
void display()
{
    struct node *top_temp = top;
    int item;
    if(top_temp == NULL)
        return ;
    while(top_temp != NULL)
    {
        item = top_temp -> data;
        printf("%d  ",item);
        top_temp = top_temp -> link;
    }
    printf("\n");
    return ;
}
