#include <iostream>
using namespace std;
class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        setHours(h);
        setMinutes(m);
        setSeconds(s);
    }

    void setHours(int h) {
        if (h >= 0 && h <= 23) {
            hours = h;
        } else {
            std::cout << "Invalid hours value. Setting to 0." << std::endl;
            hours = 0;
        }
    }

    // Аналогично за setMinutes и setSeconds

    void print24HourFormat() const {
        std::cout << std::setw(2) << std::setfill('0') << hours << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << std::endl;
    }

    void print12HourFormat() const {
        std::string amPm = hours < 12 ? "AM" : "PM";
        int h12 = hours % 12;
        std::cout << std::setw(2) << std::setfill('0') << h12 << ":"
                  << std::setw(2) << std::setfill('0') << minutes << ":"
                  << std::setw(2) << std::setfill('0') << seconds << " "
                  << amPm << std::endl;
    }
};

int main() {
    Time time(13, 24, 5);
    time.print24HourFormat();
    time.print12HourFormat();
    return 0;
}