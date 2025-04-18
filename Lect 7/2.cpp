#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inputFile("Matrix.txt"); // mở file đầu vào matrix.txt
    if (!inputFile) {
        cerr << "Không thể mở file đầu vào." << endl;
        return 1;
    }

    ofstream outputFile("Matrix.out"); // mở file đầu ra matrix.out
    if (!outputFile) {
        cerr << "Không thể mở file đầu ra." << endl;
        return 1;
    }

    int m, n;
    inputFile >> m >> n; // đọc số hàng và số cột

    int a[100][100]; // giả sử ma trận tối đa 100x100

    // đọc ma trận từ file
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            inputFile >> a[i][j];

    inputFile.close(); // đóng file sau khi đọc xong

    // tạo mảng prefix sum theo hàng
    int prefix[100][101] = {0}; // prefix[i][j] là tổng từ cột 0 đến j-1 của hàng i
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            prefix[i][j + 1] = prefix[i][j] + a[i][j];
        }
    }

    int max_sum = -10000000; // khởi tạo tổng lớn nhất là một số âm lớn
    int r1 = 0, c1 = 0, r2 = 0, c2 = 0; // tọa độ của hình chữ nhật có tổng lớn nhất

    // duyệt qua mọi cặp cột left và right
    for (int left = 0; left < n; ++left) {
        for (int right = left; right < n; ++right) {
            // mảng lưu tổng của các hàng từ cột left đến cột right
            int temp[100] = {0};
            for (int row = 0; row < m; ++row) {
                temp[row] = prefix[row][right + 1] - prefix[row][left];
            }

            // duyệt brute-force các đoạn liên tiếp trong mảng temp để tìm tổng lớn nhất
            for (int top = 0; top < m; ++top) {
                int sum = 0;
                for (int bottom = top; bottom < m; ++bottom) {
                    sum += temp[bottom];
                    if (sum > max_sum) {
                        max_sum = sum;
                        r1 = top + 1;   // chuyển về chỉ số bắt đầu từ 1 như đề bài yêu cầu
                        c1 = left + 1;
                        r2 = bottom + 1;
                        c2 = right + 1;
                    }
                }
            }
        }
    }

    // ghi kết quả ra file output
    outputFile << r1 << " " << c1 << " " << r2 << " " << c2 << " " << max_sum << endl;
    outputFile.close();
    return 0;
}
