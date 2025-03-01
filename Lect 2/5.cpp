#include <iostream>
using namespace std;

class Stack {
    int values[100];
    int countValue;
    
public:
    // Construction & destruction
    Stack() {
        countValue = 0;
    }
    ~Stack() {}
    
    // Print
    void printStack() {
        for (int i = 0; i < countValue; i++) {
            cout << values[i] << ' ';
        }
        cout << endl;
    }

    
    // Push & pop
    void push(int value) {
        if (countValue == 100) {
            return;
        }
        values[countValue] = value;
        countValue ++;
    }
    void pop() {
        if (countValue != 0) {
            countValue --;
        }
    }
};

int main() {
    Stack myStack;

    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    myStack.push(4);
    myStack.pop();
    myStack.pop();
    myStack.push(5);
    
    myStack.printStack();

    return 0;
}