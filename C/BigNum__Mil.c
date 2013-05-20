#include <stdio.h>
#include <memory.h>
#include <string.h>

struct Bigint
{
int len;
int digits[1000];
};

struct Bigint a,b,c;

main()
{
    char str[1000];
    int i,j;
    
    puts("Input two large integers:");
    
    scanf("%s",str);
    a.len=strlen(str);
    memset(a.digits,0,sizeof(a.digits));
    for (i=0;i<a.len;i++)
        a.digits[i]=str[a.len-1-i]-'0';
        
    scanf("%s",str);
    b.len=strlen(str);
    memset(b.digits,0,sizeof(b.digits));
    for (i=0;i<b.len;i++)
        b.digits[i]=str[b.len-1-i]-'0';
        
    c.len=a.len+b.len;
    memset(c.digits,0,sizeof(c.digits));
    for (i=0;i<a.len;i++)
        for (j=0;j<b.len;j++)
            c.digits[i+j]+=a.digits[i]*b.digits[j];
            
    for (i=0;i<c.len;i++)
        if (c.digits[i]>9)
        {
            c.digits[i+1]+=c.digits[i]/10;
            c.digits[i]%=10;
            while (c.digits[c.len])
                c.len++;
        }
        
    puts("The product of the two integers is");
    for (i=c.len-1;i>=0;i--)
        printf("%d",c.digits[i]);
    putchar('\n');
    
    system("pause");
} 
