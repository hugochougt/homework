#include<cstdio>
#include<cstring>
using namespace std;
void add(char *str1, char *str2, char *str3)
{
    int i,j,i1,i2,tmp,carry;
    int len1=strlen(str1),len2=strlen(str2);
    char ch;
    
    i1=len1-1;i2=len2-1;
    j=carry=0;
    
    for(;i1>=0&&i2>=0;++j,--i1,--i2)
    {
        tmp=str1[i1]-'0'+str2[i2]-'0'+carry;
        carry=tmp/10;
        str3[j]=tmp%10+'0';
    }
    while(i1>=0)
    {
        tmp=str1[i1--]-'0'+carry;
        carry=tmp/10;
        str3[j++]=tmp%10+'0';
    }
    while(i2>=0)
    {
        tmp=str2[i2--]-'0'+carry;
        carry=tmp/10;
        str3[j++]=tmp%10+'0';
    }
    if(carry) str3[j++]=carry+'0';
    str3[j]='\0';
    
    for(i=0,--j;i<j;++i,--j)
    {
        ch=str3[i];
        str3[i]=str3[j];
        str3[j]=ch;
    }
}

int main()
{
    char a[100],b[100],c[100];
    while(1)
    {
        gets(a);
        gets(b);
        add(a,b,c);
        puts(c);
    }
    //system("pause");
    return 0;
}
