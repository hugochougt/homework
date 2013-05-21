//Bignum_Mult
#include<iostream>
#include<cstring>
using namespace std;
const int MAXSIZE = 200;
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
    char str1[MAXSIZE],str2[MAXSIZE],str3[MAXSIZE];
    while(1)
    {
        gets(str1);
        gets(str2);
        memset(str3,'0',sizeof(str3));
        Mul(str1,str2,str3);
        puts(str3);
    }
    return 0;
}
