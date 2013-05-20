#include <stdio.h>
int main()
{
    char str[81];
    int i=0;
    printf("Enter string: ");
    gets(str);
    while(str[i]!='\0')
        i++;
    printf("The length of the string is %d.\n",i);
    getch();
    return 0;
}
