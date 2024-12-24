#include <iostream>
using namespace std;

int main(){
    double* p; 
    double j = 3;
    p = &j;
    cout<< "Value of p "<<*p<<endl;
    cout<< "Address of &p "<<&p<<endl;
    cout<< "Value of p size "<<sizeof p<<endl;
    return 0;
}