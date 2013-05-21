#include<iostream>
using namespace std;
class Process
{
    static int instance;
public:
    Process()
    {
        instance++;    
    }
    ~Process()
    {
        instance--;
    }
    static void print()
    {
        cout << "number of instance: " << instance << endl;     
    }
};
int Process::instance = 0;
int main()
{
    Process *p1,*p2;
    
    p1 = new Process;
    p1->print();
    p2 = new Process;
    p2->print();
    
    delete p1;
    Process::print();
    delete p2;
    Process::print();
    system("pause");
    return 0;
}
