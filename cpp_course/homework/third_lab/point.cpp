#include <iostream>
#include <math.h>

using namespace std;

class point
{
    private:
        double x;
        double y;
    public: 
        point(double xcoord, double ycoord);
        void print();
        double dist(const point &p1, const point &p2);
        ~point();
};
point::point(double xcoord, double ycoord)
{
    cout << "Creating point ("<<xcoord<<","<<ycoord<<")"<<endl;
    x = xcoord;
    y = ycoord;
}
void point::print()
{
    cout << "Point: ("<<x<<","<<y<<")"<<endl;
}
double point::dist(const point &p1, const point &p2) 
{
 return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
point::~point()
{
    point a(3,4), b(10,4);
    cout << "Distance between "; a.print();
    cout <<" and "; b.print();
    cout <<" is "; a.dist(a,b); 
    cout << endl;
}
