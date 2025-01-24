#ifndef _SAVINGS_ACCOUNT_H_
#define _SAVINGS_ACCOUNT_H_
#include "account.h"

class SavingsAccount : public Account {
    public:
        double interest_rate;
        void setInterestRate(double rate);
        double getInterestRate();
        void deposit(double amount);
        void withdraw(double amount);
        SavingsAccount();
        ~SavingsAccount();
};

#endif