#include<iostream>
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
    int t,i,n;
    char str[1006][500]={"0","1","1"};
    for(i=3;i<=1001;i++)
        add(str[i-2],str[i-1],str[i]);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<str[n]<<endl;    
    }
    return 0;
}
