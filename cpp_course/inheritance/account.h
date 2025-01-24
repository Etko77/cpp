#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
using namespace std;
#include <string>

class Account{
    public:
        double balance;
        string name;
        void deposit(double amount);
        void withdraw(double amount);
        Account();
        ~Account();
};
#endif

