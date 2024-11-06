#include <iostream>
#include <stack>

using namespace std;


class Stack {
public:
    stack<char> data;

    void push(char c) {
        data.push(c);
    }

    void pop() {
        if (!data.empty()) {
            data.pop();
        } else {
            cout << "Стекът е празен!" << endl;
        }
    }

    bool empty() {
        return data.empty();
    }

    char top() {
        if (!data.empty()) {
            return data.top();
        } else {
            cout << "Стекът е празен!" << endl;
            return '\0'; // Връща нулев символ при празен стек
        }
    }
};

Stack loadstack(int upper) {
    Stack stack;
    char start = (upper == 1) ? 'A' : 'a';
    char end = start + 25;

    for (char c = start; c <= end; c++) {
        stack.push(c);
    }

    return stack;
}

int main() {
   
    Stack upperStack = loadstack(1);

    while (!upperStack.empty()) {
        cout << upperStack.top() << " ";
        upperStack.pop();
    }
    cout << endl;

    Stack lowerStack = loadstack(0);

    while (!lowerStack.empty()) {
        cout << lowerStack.top() << " ";
        lowerStack.pop();
    }
    cout << endl;

    return 0;
}