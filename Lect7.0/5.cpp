#include <iostream>
using namespace std;

// đếm số chữ số của n bằng đệ quy
int countDigits(int n) {
    if (n < 10) return 1;
    return 1 + countDigits(n / 10);
}

int main() {
    int n;
    // nhập n từ bàn phím
    cin >> n;
    // in ra số chữ số của n
    cout << countDigits(n);
    return 0;
}
