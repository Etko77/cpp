#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base()
        : value {0}  { 
            cout << "Base no values constructor" << endl; 
    }
    Base(int x) 
        : value {x} { 
            cout << "int Base constructor" << endl;
    }
    Base(const Base &other) 
        : value {other.value} {
         cout << "Base copy constructor" << endl;     
    }
        
    Base &operator=(const Base &rhs)  {
    cout << "Base operator=" << endl;
        if (this == &rhs)
            return *this;
        value = rhs.value;
        return *this;
    }
            
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived: public Base{
    private: 
        int double_value;
    public:
        Derived():Base(),double_value{0}{
            cout<<"Derived no values constructor"<<endl;
        }
        Derived(int x):Base(x),double_value(x*2){
            cout<<"Derived constructor with values"<<endl;
        }
        Derived(const Derived &other):Base(other),double_value(other.double_value){
            cout<<"Derived copy constructor"<<endl;
        }
        Derived &operator=(const Derived &rhs){
            cout<<"Derived operator="<<endl;
            if(this == &rhs){
                return *this;
            }
            Base::operator=(rhs);
            double_value = rhs.double_value;
            return *this;
        }
        ~Derived(){cout<<"Destructor of derived"<<endl;}
};

int main() {
//    Base b {100};   // Overloaded constructor
//    Base b1 {b};    // Copy constructor
//    b = b1;          //   Copy assignment

    Derived d {100};    // Overloaded constructor
    Derived d1 {d};     // Copy constructor
    d = d1;                // Copy assignment
    
    return 0;
}