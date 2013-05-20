#incldue <stdio.h>
#incldue <string.h>

void call(char *s)
{
    int l = strlen(s);
    char *t = (s + l - 1);
    printf("%s",t);
}

int main()
{
    char str[80];
    gets(str);
    call(str);
    system("pause");    
}
