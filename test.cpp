#include <iostream>
using namespace std;

class Account
{
    private:
        string name;
        double balance;
    public:
        string get_name(){return name;}
        void set_name(string n){name = n;}
        double get_balance(){return balance;}
        void set_balance(double b){balance = b ;}

        void deposit(double sum){set_balance(balance+sum);};
        double withdrawal(double sum){
            if (balance >= sum){
                set_balance(balance-sum);
                return sum;
            }else{
                cout<<"Not enough to with draw"<<endl;
            }
        }
        Account(string n, double b){
            name = n;
            balance = b;
        }
        // Account(){
        //     name = "Blank";
        //     balance = 0.00;
        // }
        Account():name{"Blank"},balance{0.00}{

        }
        // ~Account(){
        //     delete name;
        //     delete balance;
        // }
};
class Deep{
    private:
        int* data;
    public:
        void set_data(int d){*data = d;}
        int get_data(){return *data;}
        
    Deep(int d = 0){
        data = new int;
        *data = d;
    }
    Deep(const Deep &source):Deep{*source.data}{
        cout<<"Copy constructor deep copy."<<endl;
    }
    ~Deep(){
        delete data;
        cout<<"Freeing storage used at the heap"<<endl;
    }
};
class Animal{
    private:
        string name;
        int age;
        string type;
    public:
        Animal(string n = "Blank",int a = 0, string t = "Unkowkn"){
            name = n;
            age = a;
            type = t;
        };

        string get_name(){return name;};
};

int main(){
    double* p; 
    double j = 3;
    p = &j;
    cout<< "Value of p "<<*p<<endl;
    cout<< "Address of &p "<<&p<<endl;
    cout<< "Value of p size "<<sizeof p<<endl;
    Account bobby = Account();
    cout<<bobby.get_name()<<endl;
    Animal ani = Animal();
    cout<<ani.get_name()<<endl;
    
    int three = 3;
    int*i = &three;
    Deep d = Deep(*i);
    {
        cout<<"hello there!"<<endl;
    }

    return 0;
}