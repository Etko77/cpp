#include <iostream>

using namespace std;

class Base {
private:
    int value;
public:
   Base() : value{0} { cout << "Base no-args constructor" << endl; }
   Base(int x) : value{x} { cout << "Base (int) overloaded constructor" << endl; }
   ~Base(){ cout << "Base destructor" << endl; }
};

class Derived : public Base {
    using Base::Base;
private:
    int doubled_value;
public:
    Derived() : doubled_value {0} { cout << "Derived no-args constructor " << endl; } 
    Derived(int x,int x2) :Base(x), doubled_value {x2*2}  { cout << "Derived (int) overloaded constructor" << endl; }
    ~Derived() { cout << "Derived destructor " << endl; } 
};

int main() {
//   Base b;
//    Base b{100};
 //   Derived d;
    Derived d {10, 1000};
    
    return 0;
}