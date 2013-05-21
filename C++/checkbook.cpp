// checkbook.cpp - The function for the Checkbook class

#include "checkbook.h"

void Checkbook::setBalance(float amount)
{
    balance = amount;    
}

bool Checkbook::writeCheck(float amount)
{
    if(amount > balance)
        return false;
    balance -= amount;
    lastCheck = amount;
    return true;    
}

void Checkbook::deposit(float amount)
{
    balance += amount;
    lastDeposit = amount;    
}

float Checkbook::getBalance()
{
    return balance;    
}

float Checkbook::getLastCheck()
{
    return lastCheck;    
}

float Checkbook::getLastDeposit()
{
    return lastDeposit;    
}
