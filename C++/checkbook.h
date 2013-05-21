// checkbook.h - A class template for checkbook,
// where the check is any data type
template <class DataType> 
class Checkbook
{
    public:
        Checkbook(){};
        ~Checkbook(){};
        void setBalance(float amount);
        bool writeCheck(DataType amount);
        
        void deposit(float amount);
        float getBalance();
        DataType getLastCheck();
        float getLastDeposit();
    private:
        float balance;
        DataType lastCheck;
        float lastDeposit;
};

//The function definitions of the class template for the checkbook

template <class DataType>
void Checkbook<DataType>::setBalance(float amount)
{
    balance = amount;    
}

template <class DataType>
bool Checkbook<DataType>::writeCheck(DataType amount)
{
    if(amount > balance)
        return false;
    balance -= amount;
    lastCheck = amount;
    return true;    
}

template <class DataType>
void Checkbook<DataType>::deposit(float amount)
{
    balance += amount;
    lastDeposit = amount;    
}

template <class DataType>
float Checkbook<DataType>::getBalance()
{
    return balance;    
}

template <class DataType>
DataType Checkbook<DataType>::getLastCheck()
{
    return lastCheck;    
}

template <class DataType>
float Checkbook<DataType>::getLastDeposit()
{
    return lastDeposit;    
}
