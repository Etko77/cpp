#include <iostream>
#include "savingAccount.h"
using namespace std;

SavingsAccount::SavingsAccount():interest_rate{0.0}{
}
SavingsAccount::~SavingsAccount(){
}
void SavingsAccount::setInterestRate(double rate){
    interest_rate = rate;
}
double SavingsAccount::getInterestRate(){
    return interest_rate;
}
void SavingsAccount::deposit(double amount){
    balance += amount;
    cout<<amount<<" has been deposited and the total balance is "<<balance<<endl;
};
void SavingsAccount::withdraw(double amount){
    if(amount > balance){
        cout<<"Insufficient funs"<<endl;
    }else{
        balance -= amount;
        cout<<amount<<" has been withdrawn from the account with a remaining total balance of "<<balance<<endl;
    }
}