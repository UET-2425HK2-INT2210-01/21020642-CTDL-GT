#include <iostream>
#include <string>
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
    int n;
    cin >> n;
    cin.ignore();
    
    Stack myStack;
    
    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        string op;
        int x;
        
        size_t space = line.find(' ');
        op = line.substr(0, space);
        
        if (op == "push") {
            x = stoi(line.substr(space + 1));
            myStack.push(x);
        } else if (op == "pop") {
            myStack.pop();
        }
    }
    // myStack.push(1);
    // myStack.push(2);
    // myStack.push(3);
    // myStack.push(4);
    // myStack.pop();
    // myStack.pop();
    // myStack.push(5);
    
    myStack.printStack();

    return 0;
}