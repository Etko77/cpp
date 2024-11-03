#include <iostream>
#include <vector>

class Worker {
private:
    int socialNumber;
    std::string name;
    int yearsOfExperience;
    std::string position;
    std::vector<double> salaries; // Използваме вектор за динамичен списък от заплати

public:
    // Конструктор по подразбиране
    Worker() : socialNumber(0), yearsOfExperience(0) {
        std::cout << "Въведете текущата длъжност: ";
        std::cin >> position;
    }

    // Конструктор с параметри (може да се добави)
    // Worker(int sn, const std::string& n, int yoe, const std::string& pos, const std::vector<double>& s) { ... }

    // Сетъри и гетъри (пример за сетъра на името)
    void setName(const std::string& newName) {
        name = newName;
    }

    std::string getName() const {
        return name;
    }

    // ... (останалите сетъри и гетъри)

    void addSalary(double salary) {
        salaries.push_back(salary);
    }

    double calculateAverageSalary() const {
        if (salaries.empty()) {
            return 0.0; // Няма заплати за изчисляване
        }

        double sum = 0.0;
        for (double salary : salaries) {
            sum += salary;
        }
        return sum / salaries.size();
    }

    double findMinSalary() const {
        if (salaries.empty()) {
            return 0.0; // Няма заплати за сравнение
        }

        double minSalary = salaries[0];
        for (double salary : salaries) {
            if (salary < minSalary) {
                minSalary = salary;
            }
        }
        return minSalary;
    }
};