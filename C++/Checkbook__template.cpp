#include<iostream>
#include<string>
#include<iomanip>
#include"checkbook.h"

using namespace std;

struct Mycheck
{
    float amt;
    int checkNum;
    string checkComment;
    bool operator >(float bal)
    {
        if(amt > bal)
            return true;
        else
            return false;
    }    
};

void operator -=(float & bal, Mycheck ch)
{
    bal -= ch.amt;    
}

int main(void)
{
    Checkbook<float> johnsCheckbook;
    Checkbook<Mycheck> susansCheckbook;
    
    Mycheck susansCheck;
    float amount;
    bool johnsCheckAccepted = false, susansCheckAccepted = false;
    
    johnsCheckbook.setBalance(1000);
    susansCheckbook.setBalance(2000);
    
    cout << "John, your balance is $1000.00." << endl;
    cout << "Susan, your balance is $2000.00." << endl;
    
    cout << "John, enter your check amount: $";
    cin >> amount;
    if(johnsCheckbook.writeCheck(amount))
    {
        cout << "Your balance is accepted." << endl;
        johnsCheckAccepted = true;
    }
    else
        cout << "Your balance was not high enough to cover the check." << endl;
        
    cout << "Susan, enter the check number of your check: " << endl;
    cin >> susansCheck.checkNum;
    cin.ignore();
    cout << "Please also enter any comment you wish to make about the check: " << endl;
    getline(cin, susansCheck.checkComment);
    cout << "Susan, enter your check amount: $";
    cin >> susansCheck.amt;
    if(susansCheckbook.writeCheck(susansCheck))
    {
        cout << "Your check was accepted." << endl;
        susansCheckAccepted = true;
    }
    else
        cout << "Your balance was not high enough to cover the check." << endl;
        
    cout << fixed << showpoint << setprecision(2);
    cout << "John, your balance is $" << johnsCheckbook.getBalance() << endl;
    if(johnsCheckAccepted)
        cout << "Your last check amount is $" << johnsCheckbook.getLastCheck() << endl;
    cout << "Susan, your balance is $" << susansCheckbook.getBalance() << endl;
    if(susansCheckAccepted)
    {
        Mycheck testSusansCheck;
        testSusansCheck = susansCheckbook.getLastCheck();
        cout << "Your last check amount is $" << testSusansCheck.amt << endl;
        cout << "For check number: " << testSusansCheck.checkNum << endl;
        cout << "With check comment: " << testSusansCheck.checkComment << endl;
    }
    system("pause");
    return 0;
}
