#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node(char d, Node* n = nullptr) : data(d), next(n) {}
};

class Stack {
private:
    Node* top;
public:
    Stack() : top(nullptr) {}
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    void push(char c) {
        top = new Node(c, top);
    }
    void pop() {
        if (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
    char peek() {
        return top ? top->data : '\0';
    }
    bool isEmpty() {
        return top == nullptr;
    }
};

bool isValid(string s) {
    Stack stack;
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            stack.push(c);
        } else {
            if (stack.isEmpty()) return false;
            char top = stack.peek();
            if ((c == ')' && top == '(') || (c == ']' && top == '[') || (c == '}' && top == '{')) {
                stack.pop();
            } else {
                return false;
            }
        }
    }
    return stack.isEmpty();
}

int main() {
    string s;
    while (cin >> s) {
        cout << (isValid(s) ? "Valid" : "Invalid") << endl;
    }
    return 0;
}
