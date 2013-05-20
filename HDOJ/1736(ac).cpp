#include <iostream>
#include <string>
using namespace std;
 
int main()
{
 //wchar_t ch;
 //wcin.imbue(locale("chs"));   //这里不能用wchar_t来输入输出汉字
 
 //wcout.imbue(locale("chs"));
 int flag = 0;  // 0表示左边，1表示右边
 char article[1000000];
    while(gets(article) != NULL)
    {
     flag = 0;
     int len = strlen(article);
      for(int i=0; i<len; ++i)
   { 
      string tmp ;
   tmp =  tmp+article[i] + article[i+1];   // 这里判断是否遇到了"“"或"”"
          if(tmp=="“" || tmp=="”")
              flag = !flag;  
   if(article[i] == ',')
               cout << "，";
        else if(article[i] == '.')
                  cout << "。";
           else if(article[i] == '!')
                 cout << "！";
           else if(article[i] == '"')
           {
                if(flag == 0)
                    cout << "“";
                else
                    cout << "”";
                flag = !flag;
            }
            else if(article[i] == '<' && article[i+1]=='<')
            {
                  cout << "《";
                  i++;
            }
            else if(article[i] == '>' && article[i+1]=='>')
            {
                  cout << "》";
                  i++;
            }
             else if(article[i] == '?')
                 cout << "？";
             else
                  cout << article[i];
  }
  cout << endl;
    }
 return 0;
}
