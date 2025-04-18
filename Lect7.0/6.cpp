#include <iostream>
using namespace std;

// tính tổng các chữ số của n bằng đệ quy
int digitSum(int n) {
    if (n == 0) return 0;
    return n % 10 + digitSum(n / 10);
}

int main() {
    int n;
    // nhập n từ bàn phím
    cin >> n;
    // in ra tổng các chữ số
    cout << digitSum(n);
    return 0;
}
