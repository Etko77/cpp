#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include "account.h"
#include "savingAccount.h"

int main()
{   
    Account a {};
    a.deposit(2000.0);
    a.withdraw(1000.0);

    SavingsAccount s {};
    s.deposit(2000.0);
    s.withdraw(1000.0);

    Account *p_a {nullptr};
    p_a = new Account();
    p_a->deposit(1000);
    p_a->withdraw(500);
    delete p_a;

    SavingsAccount *p_savingAcc{nullptr};
    p_savingAcc = new SavingsAccount();
    p_savingAcc->deposit(1000);
    p_savingAcc->withdraw(500);
    delete p_savingAcc;

    return 0;
}