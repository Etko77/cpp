#include <iostream>
using namespace std;

class vehicle {
        int num_wheels;
        int range;
    public: 
        vehicle(int w, int r){
            num_wheels = w; range = r;
        }
        void showv()
        {
            cout << "Wheels: "<< num_wheels << endl;
            cout << "Range: "<< range << endl;
        }
};
enum motor{gas, electric, diesel};

class motorized: virtual public vehicle {
        enum motor mtr;
    public: 
        motorized(enum motor m, int w, int r): vehicle(w,r)
        {
            mtr = m ;
        }
        void showm(){
            cout << "Motor:";
            switch(mtr){
                case gas : cout << "Gas \n";
                    break;
                case diesel: cout << "Diesel \n";
                    break;
                case electric: cout << "Electric \n";
                    break;
            }
        }

};
class road_use: virtual public vehicle {
        int passengers;
    public:
        road_use(int p, int w, int r): vehicle(w,r)
        {
            passengers = p;
        }
};

int main(){
    
    return 0;
}