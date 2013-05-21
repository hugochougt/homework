#include<iostream>
using namespace std;

class Integer 
{
      private:
              int num;
      public:
             Integer(int n=0):num(){}
             void Set (int n){num=n;}
             int Get()const{return num;}
             Integer operator++(){return Integer(++num);}
             Integer operator++(int i){return Integer(num++);}
             friend Integer operator--(Integer &a)
             {return Integer(--a.num);}
};
Integer operator--(Integer &a,int i)
{
        Integer tem=a;
        a=Integer(a.Get()-1);
        return tem;
}
int main()
{
    Integer i,j;
    i.Set(6);
    j=++i;
    cout<<i.Get()<<","<<j.Get()<<endl;
    
    i.Set(6);
    j=i++;
    cout<<i.Get()<<","<<j.Get()<<endl;
    
    i.Set(6);
    j=--i;
    cout<<i.Get()<<","<<j.Get()<<endl;
    
    i.Set(6);
    j=i--;
    cout<<i.Get()<<","<<j.Get()<<endl;
    
    system("pause");
    return 0;
}    
