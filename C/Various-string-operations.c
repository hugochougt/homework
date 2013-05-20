//Various string operations
#include <stdio.h>
#include <string.h>

int ssearch(char *, char );
void reverse(char *);
//int setat(char * , char , int );

int main()
{
    char str[80];
    char ch, ch1, *s;
    int i, n;
    
    printf("Enter a string: ");
    gets(str);
    
    printf("\nEnter a character to search: ");
    scanf("%c",&ch);
    
    //check for the first occurrence of a character
    i = ssearch(str, ch);
    if(i != -1)
        printf("The first occurrence of character %c is found at No.%d\n",ch, i);
    else
        printf("Character %c is not present in the list.\n",ch);
    
    reverse(str);
    printf("\nReverse string: %s\n",str);
    
    system("pause");
    return 0;
}

//check for the first occurrence of a character
int ssearch(char *s, char ch)
{
    int i = 0;
    while( *s )
    {
        if(*s == ch)
            return i;
        i++;
        s++;    
    } 
    return -1;
}

void reverse(char *s)
{
    int l = strlen(s);
    char *t = (s + l -1);
    char ch;
    int i = 0;
    l /= 2;
    while(i < l)
    {
        ch = *s;
        *s = *t;
        *t = ch;
        
        s++;
        t--;
        i++;    
    }
}
