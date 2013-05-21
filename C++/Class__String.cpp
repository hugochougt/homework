#include <iostream>
#include <cstring>
using namespace std;
class String
{
private:
    char *str;
public:
    String(char s[]);
    ~String();
    String(const String &s);
    String &operator=(const String &s);
    char &operator[](int index);
    friend ostream &operator<<(ostream &out, const String &s);
};
String::String(char s[])
{
    str = new char[strlen(s)+1];
    strcpy(str,s);    
}
String::~String()
{
    delete []str;    
}
String::String(const String &s)
{
    str = new char[strlen(s.str)+1];
    strcpy(str, s.str);    
}
String& String::operator=(const String &s)
{
    if(this != &s)
    {
        delete []str;
        str = new char[strlen(s.str)+1];
        strcpy(str, s.str);    
    }
    return *this;
}
char& String::operator[](int index)
{
    return str[index];
}
ostream &operator<<(ostream &out, const String &s)
{
    cout << s.str;
    return out;    
}
int main()
{
    char *s="Hugo is a bad boy.";
    String s1(s);
    String s2(s1);
    cout << s1 << endl;
    cout << s2 << endl;
    char ss[10]="123456789";
    String s4(ss);
    String s3=s4;
    //s3 = s4;
    cout << s3 << s3[1] << endl;
    system("pause");
    return 0;
}
