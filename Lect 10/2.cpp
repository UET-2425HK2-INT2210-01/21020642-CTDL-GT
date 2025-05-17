#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // danh sách kề để lưu các cạnh có hướng
    vector<vector<int>> adj(n + 1);
    // mảng lưu khoảng cách (số cạnh) từ X đến các đỉnh
    vector<int> dist(n + 1, -1); // -1 nghĩa là chưa được thăm

    // đọc m cạnh và xây danh sách kề
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // vì là đồ thị có hướng, chỉ push từ u → v
    }

    // dùng hàng đợi để duyệt BFS
    queue<int> q;
    q.push(X);
    dist[X] = 0; // khoảng cách từ X đến X là 0

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        // duyệt các đỉnh kề với u
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1; // cập nhật khoảng cách đến v
                q.push(v);
            }
        }
    }

    cout << dist[Y] << endl; // nếu không có đường đi thì sẽ in ra -1

    return 0;
}
