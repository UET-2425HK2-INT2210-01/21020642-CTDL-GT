#include <iostream>
using namespace std;

int gcd(int x, int y) {
    // điều kiện dừng: nếu y = 0 thì GCD là x
    if (y == 0) {
        return x;
    }
    // đệ quy: gọi hàm gcd với tham số là y và x % y
    return gcd(y, x % y);
}

int main() {
    int X, Y;
    
    // nhập vào hai số X và Y
    cin >> X;
    cin >> Y;

    // ttính và in ra GCD
    cout << gcd(X, Y) << endl;

    return 0;
}
