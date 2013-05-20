#include <iostream>
using namespace std;        
int main(){
    int n,n1,n2,temp;
cin>>n;
while(n--)
{
    cin>>n1>>n2;
if(n1>n2){temp=n1;n1=n2;n2=temp;}
if(n1<=6){
    if(n2<6){cout<<'0'<<endl;}
    if(n2>=6&&n2<28){cout<<'1'<<endl;}
    if(n2>=28&&n2<496){cout<<'2'<<endl;}
    if(n2>=496&&n2<8128){cout<<'3'<<endl;}
    if(n2>=8128){cout<<'4'<<endl;}
}
if(n1>6&&n1<=28){
    if(n2<28){cout<<'0'<<endl;}
    if(n2>=28&&n2<496){cout<<'1'<<endl;}
    if(n2>=496&&n2<8128){cout<<'2'<<endl;}
    if(n2>=8128){cout<<'3'<<endl;}
}
if(n1>28&&n1<=496){
    if(n2<496){cout<<'0'<<endl;}
    if(n2>=496&&n2<8128){cout<<'1'<<endl;}
    if(n2>=8128){cout<<'2'<<endl;}
}
if(n1>496&&n1<=8128){
    if(n2<8128){cout<<'0'<<endl;}
    if(n2>=8128){cout<<'1'<<endl;}
}
if(n1>8128){cout<<'0'<<endl;}
}
return 0;
}
