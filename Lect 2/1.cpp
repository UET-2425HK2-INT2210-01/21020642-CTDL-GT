#include <iostream>
using namespace std;

int* inputArray (int n) {
    int* res = new int[n];
    for (int i = 0; i < n; i ++) {
        cin >> res[i];
    }
    
    return res;
}

int findPairs (int* a, int size) {
    int res = 0;
    for (int i = 0; i < size - 1; i ++) {
        for (int j = i + 1; j < size; j ++) {
            if (a[i] == a[j]) {
                res ++;
            }
        }
    }
    
    return res;
}

int main () {
    int n;
    cin >> n;
    int* A = inputArray(n);
    cout << findPairs(A, n);
    
    delete [] A;
    return 0;
}