#include<stdio.h>
#include<string.h>
void swap(int *a, int *b)
{
    int t;
    t=*a;
    *a=*b;
    *b=t;    
}
int main(void)
{
    char s[1002];
    int i,len,a,h,p;
    while(gets(s))
    {
        len=strlen(s);
        for(i=0,a=0,p=0,h=0;i<len;i++)
            if(s[i]=='a')
                a++;
            else if(s[i]=='h')
                h++;
            else if(s[i]=='p')
                p++;
        p/=2;
        if(a>h)
            swap(&a, &h);
        if(h>p)
            swap(&h, &p);
        if(h>a)
            swap(&h, &a);
        printf("%d\n",a);    
    }    
    return 0;
}
