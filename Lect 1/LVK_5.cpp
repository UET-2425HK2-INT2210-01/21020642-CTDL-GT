// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    
    double arr[5];
    cout << "Now input array: ";
    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sum of the greatest and smallest: ";

    cout << arr[0] + arr[4];

    return 0;
}