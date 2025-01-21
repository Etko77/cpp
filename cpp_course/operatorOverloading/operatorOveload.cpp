#include <iostream>
using namespace std;

class Vector {
    private:
        float x,y;

    public:
        Vector(float x, float y): x(x),y(y){}

        Vector operator+(Vector& other){
            return Vector(this->x + other.x,this->y + other.y);
        }
        void display() const{
            cout << "Vector (" << x <<", "<<y<<")"<<endl;
        }
};

int main(){
    Vector v1(2.00,4.02);
    Vector v2(4.03,8.08);
    Vector v3 = v1+v2;

    v3.display();
    return 0;
}