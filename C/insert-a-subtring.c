//Program to insert a subtring in a string
#include <stdio.h>
#include <string.h>
#include <conio.h>

int main()
{
    void strins(char *, char *, int p);
    int pos,cont;
    char str[50],sstr[10];
    void strins(char *, char *, int pos);
    do
    {
        fflush(stdin);
        printf("\nEnter any string: ");
        gets(str);
        printf("Enter the substring to insert: ");
        gets(sstr);
        printf("Enter the position at which insertion take place: ");
        scanf("%d",&pos);
        strins(str, sstr, pos);
        printf("Do you want to continue (y/n) : ");
        scanf("%d",&cont);
        fflush(stdin);
    }while( (cont == 'Y') || (cont == 'y') );
    return 0;
}

void strins(char *os, char *ss, int p)
{
    char ns[50];
    int i,l,t,t1;
    t = p;
    for(i = 0; i < p - 1; i++)
        ns[i] = os[i];
    l = strlen(ss);
    p-=1;
    for(i = 0; i < l; i++)
    {
        ns[p] = ss[i];
        p++;    
    }
    t1 = t - 1;
    ns[p] = ' ';
    p++;
    for(; os[t1] != '\0'; t1++)
    {
        ns[p] = os[t1];
        p++;    
    }
    ns[p] = '\0';
    printf("New string after insertion is : ");
    puts(ns);
}
