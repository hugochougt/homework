//program to find the position of a substring in a string
#include <stdio.h>
#include <string.h>

int main()
{
    char str[50],sstr[50];
    char *p;
    int cont;
    do
    {
        printf("Enter any string : ");
        gets(str);
        printf("Enter the substring: ");
        gets(sstr);
        p = strstr(str, sstr);
        if(p == NULL)
        {
            printf("Substring not found.\n");
        }
        else
        {
            printf("Position of the substring in the string is %d.\n",(p-str+1));    
        }
        printf("Do you want to continue (y/n) : ");
        scanf("%d",&cont);
    }while( (cont == 'Y') || (cont == 'y') );
    return 0;
}
