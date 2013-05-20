//Program to sort strings
#include <stdio.h>
#include <string.h>

int main()
{
    int ch,i,j,n;
    char name[25][30],t[30];
    printf("Enter no. of strings ");
    scanf("%d",&n);
    printf("Enter the strings:\n");
    for(i = 0; i <= n; i++)
        gets(name[i]);
    printf("Do you want to sort in \n");
    printf("\t\t1.Ascending order...\n");
    printf("\t\t2.Descending order...\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            for(i = 0; i <= n; i++)
            {
                for(j = i + 1; j <= n; j++)
                {
                    if(strcmp(name[i], name[j]) > 0)
                    {
                        strcpy(t, name[i]);
                        strcpy(name[i], name[j]);
                        strcpy(name[j], t);
                    }    
                }    
            }
            printf("Sorted names in ascending order\n");
            for(i = 0; i <= n; i++)
                puts(name[i]);
            break;
        case 2:
            for(i = 0; i <= n; i++)
            {
                for(j = i + 1; j <= n; j++)
                {
                    if(strcmp(name[i], name[j]) < 0)
                    {
                        strcpy(t, name[i]);
                        strcpy(name[i], name[j]);
                        strcpy(name[j], t);
                    }    
                }    
            }
            printf("Sorted names in descending order\n");
            for(i = 0; i <= n; i++)
                puts(name[i]);
            break;
    }
    system("pause");
    return 0;
}
