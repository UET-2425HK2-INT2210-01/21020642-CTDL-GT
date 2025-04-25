#include <iostream>
using namespace std;

int A[50]; // mảng chứa tuổi của sinh viên
int n, X;
bool found = false;

// hàm đệ quy tìm tập con có tổng bằng X
void trySubset(int i, int sum) {
    if (sum == X) {
        found = true;
        return;
    }
    // nếu đã hết phần tử hoặc tổng đã vượt quá X hoặc đã tìm thấy rồi thì dừng
    if (i == n || sum > X || found) return;

    // chọn A[i] vào tập con: tăng tổng lên A[i] và chuyển sang phần tử tiếp theo
    trySubset(i + 1, sum + A[i]);

    // không chọn A[i]: giữ nguyên tổng, chuyển sang phần tử tiếp theo
    trySubset(i + 1, sum);
}

int main() {
    cin >> n >> X;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }

    trySubset(0, 0); // bắt đầu từ phần tử đầu tiên và tổng là 0

    if (found) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
