#include<iostream>
#include<cstring>
using namespace std;
int n,len,i,j;
char str[83];
void cir1();void cir2();void cir3();
void cir4();void cir5();void cir6();
void cir7();
int main()
{
    while(cin>>str>>n)
    {
        n=n%8;
        if(n<0)
            n+8;
        switch(n)
        {
            case 0:cout << str << endl;break;
            case 1:cir1();break;
            case 2:cir2();break;
            case 3:cir3();break;
            case 4:cir4();break;
            case 5:cir5();break;
            case 6:cir6();break;
            case 7:cir7();break;
        }
    }
    return 0;
}
void cir1()
{
    len = strlen(str) - 1;
    for(i=len;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)    
            cout << " ";
        cout << str[i] << endl;
    }
}
void cir2()
{
    len = strlen(str) / 2;
    for(i=0;str[i];i++)
    {
        for(j=0;j<len;j++)
            cout << " ";
        cout << str[i] << endl;
    }
}
void cir3()
{
    len = strlen(str) - 1;
    for(i=0;i<=len;i++)
    {
        for(j=0;j<i;j++)
            cout << " ";
        cout << str[len-i] << endl;
    }
}
void cir4()
{
    len = strlen(str) - 1;
    for(i=len;i>=0;i--)
        cout << str[i];
    cout << endl;
}
void cir5()
{
    len = strlen(str) - 1;
    for(i=len;i>=0;i--)
    {
        for(j=0;j<i;j++)    
            cout << " ";
        cout << str[len-i] << endl;
    }
}
void cir6()
{
    len = strlen(str) / 2;
    for(i=0;str[i];i++)
    {
        for(j=0;j<len;j++)
            cout << " ";
        cout << str[i] << endl;
    }
}
void cir7()
{
    len = strlen(str);
    for(i=0;i<len;i++)
    {
        for(j=0;j<i;j++)
            cout << " ";
        cout << str[i] << endl;
    }
}
