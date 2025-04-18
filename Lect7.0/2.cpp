#include <iostream>
using namespace std;

// tính giai thừa n bằng đệ quy
int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    // nhập số n từ bàn phím
    cin >> n;
    // in ra n
    cout << factorial(n);
    return 0;
}
