#include <iostream>
using namespace std;

// hàm đổi chỗ 2 số
void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}

// hàm chia mảng và trả về chỉ số pivot sau khi chia
int partition(double arr[], int low, int high) {
    double pivot = arr[high];      // chọn phần tử cuối làm pivot
    int i = low - 1;               // i là chỉ số của phần tử nhỏ hơn pivot

    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {      // nếu phần tử nhỏ hơn pivot thì tăng i và đổi chỗ với arr[j]
            i++;
            swap(arr[i], arr[j]);  // đưa phần tử nhỏ hơn về bên trái pivot
        }
    }
    swap(arr[i + 1], arr[high]);   // đưa pivot về đúng vị trí
    return i + 1;
}

// hàm quick sort đệ quy
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); // chia mảng và lấy chỉ số pivot

        quickSort(arr, low, pi - 1);        // sắp xếp bên trái pivot
        quickSort(arr, pi + 1, high);       // sắp xếp bên phải pivot
                                            // cứ như vậy gọi đệ quy cho đến khi còn 1 phần tử
    }
}

int main() {
    int n;
    cin >> n;
    double arr[1005];

    // đọc n số thực
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    // in ra mảng đã sắp xếp
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
