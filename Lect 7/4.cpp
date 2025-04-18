#include <iostream>
#include <cmath>
using namespace std;

// hàm đệ quy in tất cả các số nhị phân có độ dài n
void printBinary(int n, string binary = "") {
    // nếu độ dài của chuỗi nhị phân bằng n, in ra
    if (binary.length() == n) {
        cout << binary << endl;
        return;
    }

    // đđệ quy gọi lại với chuỗi nhị phân thêm '0 và 11
    printBinary(n, binary + "0");
    printBinary(n, binary + "1");
}

int main() {
    int n;
    cin >> n;
    
    // in tất cả các số nhị phân có độ dài n
    printBinary(n);
    
    return 0;
}
