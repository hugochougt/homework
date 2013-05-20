//program to extract substring from the string
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    void left(char *, int );
    void right(char *, int );
    void mid(char *, int , int );
    char str[50];
    int spos, nchars;
    int ch;
    do
    {
        fflush(stdin);
        printf("\nEnter the string from which extraction has to take place :");
        gets(str);
        printf("1.Left portion of the string ....\n");
        printf("2.Right portion of the string ....\n");
        printf("3.Middle portion of the string ....\n");
        printf("4.EXIT....\n");
        printf("Enter your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the number of characters to be extracted(left):");
                    scanf("%d",&nchars);
                    left(str, nchars);
                    break;
            case 2: printf("Enter the number of characters to be extracted(right):");
                    scanf("%d",&nchars);
                    right(str, nchars);
                    break;
            case 3: printf("Enter the starting position:");
                    scanf("%d",&spos);
                    printf("Enter the number of characters to be extracted(mid):");
                    scanf("%d",&nchars);
                    mid(str, spos, nchars);
                    break;
        }
    }while(ch != 4);
    return 0;
}

void left(char *os, int n)
{
    int i;
    printf("Left portion of the string extracted is ");
    for(i = 0; i < n; i++)
        printf("%c",os[i]);
}

void right(char *os, int n)
{
    int i,l=strlen(os);
    printf("Right portion of the string extracted is ");
    for(i = l - n; i <= l; i++)
        printf("%c",os[i]);    
}

void mid(char *os, int sp, int n)
{
    int i;
    printf("Middle portion of the string extracted is ");
    for(i = sp -1; i < (sp - 1 + n); i++)
        printf("%c",os[i]);    
}
