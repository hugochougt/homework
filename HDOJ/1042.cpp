#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;

void Mul(char *str1,char *str2,char *str3)
{
    int i,j,i1,i2,tmp,carry,jj;
    int len1=strlen(str1),len2=strlen(str2);
    char ch;
    jj=carry=0;
    for(i1=len1-1;i1>=0;--i1)
    {
        j=jj;
        for(i2=len2-1;i2>=0;--i2,++j)    
        {
            tmp=(str3[j]-'0')+(str1[i1]-'0')*(str2[i2]-'0')+carry;
            if(tmp>9)
            {
                carry=tmp/10;
                str3[j]=tmp%10+'0';
            }
            else
            {
                str3[j]=tmp+'0';
                carry=0;    
            }
        }
        if(carry)
        {
            str3[j]=carry+'0';
            carry=0;
            ++j;
        }
        ++jj;
    }
    --j;
    while(str3[j]=='0'&&j>0)
        --j;
    str3[++j]='\0';
    for(i=0,--j;i<j;++i,--j)
    {
        ch=str3[i];
        str3[i]=str3[j];
        str3[j]=ch;
    }
}

int main()
{
    char str[10002][500]={"1","1"},tmp[6];
    int i,n;
    for(i=2;i<=10000;i++)
    {
        itoa(i,tmp,10);
        memset(str[i],'0',sizeof(str[i]));
        Mul(str[i-1],tmp,str[i]);
    }
    while(scanf("%d",&n)!=EOF)
    {
        puts(str[n]);
    }
    return 0;
}
