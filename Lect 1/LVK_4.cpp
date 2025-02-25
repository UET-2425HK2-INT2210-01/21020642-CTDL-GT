// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

int main() {
    int N;
    cout << "Input array size: ";
    cin >> N;
    
    int arr[N];
    cout << "Now input array: ";
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    

    return 0;
}