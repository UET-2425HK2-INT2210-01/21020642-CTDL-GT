#include <iostream>
using namespace std;

// đảo ngược n bằng đệ quy có biến phụ
int reverseNum(int n, int rev = 0) {
    if (n == 0) return rev;
    return reverseNum(n / 10, rev * 10 + n % 10);
}

int main() {
    int n;
    // nhập n từ bàn phím
    cin >> n;
    // in ra số sau khi đảo ngược
    cout << reverseNum(n);
    return 0;
}
