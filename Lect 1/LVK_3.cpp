// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int a, b;
    cout << "Input two numbers: ";
    cin >> a >> b;
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    cout << "GCD: " << a;

    return 0;
}