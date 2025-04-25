#include <iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_X = 10000;

int n, X;
int weight[MAX_N], value[MAX_N];
int dp[MAX_X]; // dp[i] lưu giá trị lớn nhất với tổng trọng lượng i

int main() {
    cin >> n >> X;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // duyệt từng obj
    for (int i = 0; i < n; ++i) {
        // duyệt ngược để tránh dùng lại obj đã xét
        for (int j = X; j >= weight[i]; --j) {
            // chọn hoặc không chọn obj i
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[X] << endl; // in ra giá trị lớn nhất có thể đạt được
    return 0;
}
