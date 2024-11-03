#include <iostream>

class Line {
private:
    int len;

public:
    Line(int l) : len(l) {
        for (int i = 0; i < len; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    ~Line() {
        std::cout << "Line deleted." << std::endl;
    }
};

int main() {
    Line line(10); 
    Line line2(5);  
    return 0;
}