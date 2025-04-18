#include <iostream>
using namespace std;

// tính fibonacci thứ n bằng đệ quy
int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;
    // nhập số n từ bàn phím
    cin >> n;
    // in ra fibonacci thứ n
    cout << fib(n);
    return 0;
}
