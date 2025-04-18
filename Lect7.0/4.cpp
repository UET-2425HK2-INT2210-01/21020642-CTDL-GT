#include <iostream>
using namespace std;

// tính x^n bằng đệ quy
int power(int x, int n) {
    if (n == 0) return 1;
    return x * power(x, n - 1);
}

int main() {
    int x, n;
    // nhập x và n từ bàn phím
    cin >> x >> n;
    // in ra x^n
    cout << power(x, n);
    return 0;
}
