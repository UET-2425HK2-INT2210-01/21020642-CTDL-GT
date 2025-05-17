#include <iostream>
#include <vector>

using namespace std;

// danh sách kề để lưu các cạnh của đồ thị
vector<vector<int>> adj;
// mảng để đánh dấu các đỉnh đã được thăm
vector<bool> visited;

// hàm dfs duyệt qua các đỉnh thuộc cùng 1 thành phần liên thông
void dfs(int u) {
    visited[u] = true; // đánh dấu đỉnh u đã được thăm
    for (int v : adj[u]) {
        if (!visited[v]) {
            dfs(v); // tiếp tục duyệt các đỉnh kề với v
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);       // cấp phát danh sách kề (đánh số từ 1 đến n)
    visited.resize(n + 1);   // khởi tạo mảng visited

    // đọc m cạnh và xây dựng danh sách kề
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y); // thêm y vào danh sách kề của x
        adj[y].push_back(x); // thêm x vào danh sách kề của y (vì là đồ thị vô hướng)
    }

    int connected_components = 0; // biến đếm số thành phần liên thông

    // duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            // nếu đỉnh chưa được thăm, thì nó thuộc thành phần liên thông mới
            ++connected_components;
            dfs(i); // duyệt hết thành phần liên thông chứa đỉnh i
        }
    }

    cout << connected_components << endl;

    return 0;
}
