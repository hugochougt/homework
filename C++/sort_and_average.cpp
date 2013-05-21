#include<iostream>
using namespace std;
int main()
{
 float num[10],max,min,sum=0;
 int i,j;
 cout<<"请输入10个数："<<endl;
 for(i=0;i<10;i++)
 {
  cin>>num[i];
 }

 max=min=num[0];

 for(j=0;j<10;j++)
 {
  if(num[j]>=max) max=num[j];
     if(num[j]<=min) min=num[j];
  sum+=num[j];
 }

 cout<<"最大值为："<<max<<endl<<"最小值为："<<min<<endl<<"平均值为："<<sum/10<<endl;
 system("pause");
 return 0;
}
