//Decimal to binary converstion uses stack
#include <stdio.h>

int main()
{
    int dec, rem, stack[30],top=0;
    
    printf("Enter the decimal number: ");
    scanf("%d",&dec);
    while(dec != 0)
    {
        rem = dec % 2;
        stack[top] = rem;
        top++;
        dec /= 2;    
    }
    top -= 1;
    printf("The equivalent binary number is ");
    for(;top >= 0; top--)
        printf("%d",stack[top]);
    printf(" .\n");
    system("pause");
    return 0;
}
