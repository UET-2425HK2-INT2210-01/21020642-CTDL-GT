#include <iostream>
using namespace std;

// tính tổng từ 1 đến n bằng đệ quy
int sum(int n) {
    if (n == 1) return 1;
    return n + sum(n - 1);
}

int main() {
    int n;
    // nhập số n từ bàn phím
    cin >> n;
    // in ra tổng từ 1 đến n
    cout << sum(n);
    return 0;
}
