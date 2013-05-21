#include<iostream>
using namespace std;
class Clock
{
public:
    void SetTime(int NewH, int NewM, int NewS);
    void ShowTime();
private:
    int Hour,Minute,Second;    
};

void Clock::SetTime(int NewH=0, int NewM=0, int NewS=0)
{
    Hour=NewH;
    Minute=NewM;
    Second=NewS;    
}

inline void Clock::ShowTime()
{
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;    
}

int main(void)
{
    Clock MyClock;
    cout<<"First time set and output:"<<endl;
    MyClock.SetTime();
    MyClock.ShowTime();
    cout<<"Second time set and output:"<<endl;
    MyClock.SetTime(8,53,12);
    MyClock.ShowTime();
    system("pause");
    return 0;    
}
