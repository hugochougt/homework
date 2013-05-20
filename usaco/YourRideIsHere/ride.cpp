/*
ID:chaos-z1
LANG:C++
PROG:ride
*/
#include <fstream>
using namespace std;

unsigned long a=1,b=1; //乘法的初始化要弄成1  切记不是0

int main()
{
    ifstream fin("ride.in");
    char t=fin.get();
    do
    {
        a*=(t-64);
        t=fin.get();
    } while (t!='\n');  //判断行结束
    t=fin.get();
    do
    {
        b*=(t-64);
        t=fin.get();
    } while (t!='\n');
    fin.close();
    //fin.get可以读换行符 即'\n' do while后判断结构更方便 C++中字符变量可以参与数学运算
    //（以ASCII码的形式） 所以记得-64  （A的ASCII码是65）
   
    ofstream fout("ride.out");
    if ((a%47)==(b%47))  //两个等号 不要少打了
        fout<<"GO\n";
    else
        fout<<"STAY\n";
    fout.close();
    return 0;
}
