#include <iostream>
using namespace std;

// hoán đổi 2 phần tử
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// đệ quy sinh hoán vị
void generatePermutations(int arr[], int n, int index) {
    // in ra hoán vị khi đã duyệt hết
    if (index == n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    // duyệt qua các phần tử và hoán đổi
    for (int i = index; i < n; i++) {
        swap(arr[index], arr[i]);  // hoán đổi
        generatePermutations(arr, n, index + 1);  // đệ quy
        swap(arr[index], arr[i]);  // quay lại
    }
}

int main() {
    int n;
    cin >> n;  // nhập số n

    int arr[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;  // gán giá trị 1 đến n
    }

    generatePermutations(arr, n, 0);  // sinh hoán vị từ index 0

    return 0;
}
