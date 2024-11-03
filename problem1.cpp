#include <iostream>
#include <math.h>
using namespace std;
class triangle {
    private:
    double a, b, c;
    public:
    triangle();
    double face(); //Член-функция face() без аргумент
    double face(double *); //Член-функция face() с един аргумент
    void show(char *);
    ~triangle() { std::cout << "\n\nDestructing object triangle!\n"; }
};
triangle::triangle() //Дефиниция на конструктора
{do
 { std::cout << "\n\nEnter three values for the sides of triangle:\n";
std::cin >> a >> b >> c;
}
while(!((a>0)&&(b>0)&&(c>0)&&((a+b>c)&&((a+c)>b)&&((b+c)>a))));
}
double triangle::face() //Дефиниция на член-функция face() без аргументи
{
double p, s;
p = (a+b+c)/2;
s = sqrt(p*(p-a)*(p-b)*(p-c));
return s;
}
double triangle::face(double *p) //Предефинирана член-функция face()
{
double pp = a+b+c;
*p = pp; //Връщане на втория резултат чрез аргумент-указател
pp /= 2;
double s;
s = sqrt(pp*(pp-a)*(pp-b)*(pp-c));
return s;
}
void triangle::show(char *name) {
std::cout << "Sides of the triangle " << name << ":\n";
std::cout << "a=" << a << ",b=" << b << ",c=" << c;
}
int main()
{
    triangle tr1; //Обект tr1; извиква се конструкторът на класа
    double p,s;
    // tr1.show("tr1");
    std::cout << "\nThe face of triangle1 is s=" << tr1.face(); //Зарежда се член-функция
    // face() //без
    //  // аргумент
    //     triangle tr2; //Обект tr2; извиква се конструкторът на класа
    //     tr2.show("tr2");
    //     s=tr2.face(&p); //Зарежда се член-функция face() с аргумент
    std::cout << "\nThe face of triangle2 is s=” << s << ”, and the perimeter is p=" << p;
}