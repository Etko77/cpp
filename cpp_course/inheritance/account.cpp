#include <iostream>
#include "account.h"
using namespace std;

Account::Account():balance{0.0},name{"An account"}{
}

Account::~Account(){
}
void Account::deposit(double amount){
    if (amount > 0.0){
        cout <<amount<<" has been added to the account"<<endl;       
    }else{
        cout<<"Invalid amount"<<endl;
    }
}
void Account::withdraw(double amount){
    cout<<amount<<" has been withdrawn from the account"<<endl;
}