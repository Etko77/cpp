#include <iostream>
#include <vector>
using namespace std;

class Rectangle{
    public:
        double length;
        double width;

        Rectangle(double l, double w): length(l), width(w){};

        double area(){
            return length * width;
        }
        pair<double, double> face (double multiplier){
            double area = length * width * multiplier;
            double perimeter = 2 * (length + width);
            return make_pair(area, perimeter);

        }
        
};
int main()
{
    Rectangle rect(3,5);
    cout <<"The area of the rectangle is: "<< rect.area() << endl;
    pair< double,double> result = rect.face(2);
    cout<< "The face of the rectangle, miltiplied by 2 is: "<< result.first << endl;
    cout<<"The perimeter of the rectangle is "<< result.second <<endl;
    return 0;
}