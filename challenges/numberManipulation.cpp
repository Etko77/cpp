#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function prototypes
void print_numbers(vector<int>);
double mean_of_nums(vector<int>);
int smallest_num(vector<int>);
int largest_num(vector<int>);

int main() {
    vector<int> numerals = {3, 2, 1, 4, 5, 6, 9, 8, 7};
    char c;

    do {
        cout << "\nEnter one of the letters to choose:"
             << "\nP - Print numbers"
             << "\nM - Display mean of numbers"
             << "\nS - Display the smallest number"
             << "\nL - Display the largest number"
             << "\nQ - Quit" << endl;

        cin >> c;
        c = toupper(c);

        switch (c) {
            case 'P':
                print_numbers(numerals);
                break;
            case 'M':
                cout << "The mean of the numerals is " << mean_of_nums(numerals) << endl;
                break;
            case 'S':
                cout << "The smallest number is " << smallest_num(numerals) << endl;
                break;
            case 'L':
                cout << "The largest number is " << largest_num(numerals) << endl;
                break;
            case 'Q':
                cout << "Thank you for your time!" << endl;
                break;
            default:
                cout << "Invalid option. Try again." << endl;
                break;
        }
    } while (c != 'Q');

    return 0;
}

void print_numbers(vector<int> nums) {
    cout << "All the numbers in the list:" << endl;
    for (auto n : nums) {
        cout << n << " ";
    }
    cout << endl;
}

double mean_of_nums(vector<int> nums) {
    double sum = 0;
    for (auto n : nums) {
        sum += n;
    }
    return sum / nums.size();
}

int smallest_num(vector<int> nums) {
    int smallest = nums[0];
    for (auto n : nums) {
        if (n < smallest) {
            smallest = n;
        }
    }
    return smallest;
}

int largest_num(vector<int> nums) {
    int largest = nums[0];
    for (auto n : nums) {
        if (n > largest) {
            largest = n;
        }
    }
    return largest;
}
