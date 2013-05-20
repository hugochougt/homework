#include<stdio.h>
int main(void)
{
    int a,b;
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        a%=10;
        switch(a)
        {
            case 0:printf("0\n");break;
            case 1:printf("1\n");break;
            case 2:b%=4;
            switch(b)
            {
                case 1:printf("2\n");break;
                case 2:printf("4\n");break;
                case 3:printf("8\n");break;
                case 0:printf("6\n");break;
            };break;
            case 3:b%=4;
            switch(b)
            {
                case 1:printf("3\n");break;
                case 2:printf("9\n");break;
                case 3:printf("7\n");break;
                case 0:printf("1\n");break;
            };break;
            case 4:b%=2;
            switch(b)
            {
                case 1:printf("4\n");break;
                case 0:printf("6\n");break;
            };break;
            case 5:printf("5\n");break;
            case 6:printf("6\n");break;
            case 7:b%=4;
            switch(b)
            {
                case 1:printf("7\n");break;
                case 2:printf("9\n");break;
                case 3:printf("3\n");break;
                case 0:printf("1\n");break;
            };break;
            case 8:b%=4;
            switch(b)
            {
                case 1:printf("8\n");break;
                case 2:printf("4\n");break;
                case 3:printf("2\n");break;
                case 0:printf("6\n");break;
            };break;
            case 9:b%=2;
            switch(b)
            {
                case 1:printf("9\n");break;
                case 0:printf("1\n");break;
            };break;    
        }
    }  
    return 0;
}
