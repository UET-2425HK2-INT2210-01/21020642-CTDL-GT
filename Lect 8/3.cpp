#include <iostream>
using namespace std;

const int MAX_N = 105;
const int MAX_X = 10005;

int n, X;
int weight[MAX_N], value[MAX_N];
int dp[MAX_X]; // dp[i] lưu giá trị lớn nhất với tổng trọng số i

int main() {
    cin >> n >> X;
    for (int i = 0; i < n; ++i) {
        cin >> weight[i] >> value[i];
    }

    // duyệt từng giá trị
    for (int i = 0; i < n; ++i) {
        // duyệt ngược để tránh dùng lại giá trị đã xét
        for (int j = X; j >= weight[i]; --j) {
            // chọn hoặc không chọn giá trị i
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout << dp[X] << endl; // in ra giá trị lớn nhất có thể đạt được
    return 0;
}
