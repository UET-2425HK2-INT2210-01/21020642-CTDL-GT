#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

const int INF = 1e9; // vô cực

// hàm đảo ngược 1 vector
void reverseVector(vector<int> &v) {
    int l = 0, r = v.size() - 1;
    while (l < r) {
        swap(v[l], v[r]);
        ++l;
        --r;
    }
}

int main() {
    ifstream fin("dirty.txt");    // mở file input
    ofstream fout("dirty.out");   // mở file output

    int n, m, s, e;
    fin >> n >> m >> s >> e;  // đọc số đỉnh, số cạnh, đỉnh bắt đầu, đỉnh kết thúc

    vector<tuple<int, int, int>> edges; // danh sách cạnh cho Bellman Ford

    // ma trận khoảng cách cho Floyd warshall
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> next(n + 1, vector<int>(n + 1, -1)); // lưu đỉnh tiếp theo để truy vết

    // đọc dữ liệu cạnh
    for (int i = 0; i < m; ++i) {
        int u, v, d;
        fin >> u >> v >> d;          // cạnh từ u → v với trọng số d
        edges.push_back({u, v, d});  // lưu vào danh sách cạnh
        dist[u][v] = d;              // cập nhật khoảng cách ban đầu
        next[u][v] = v;              // dùng để truy vết trong Floyd warshall
    }

    // a) Bellman Ford từ s

    vector<int> bf_dist(n + 1, INF); // khoảng cách từ s đến các đỉnh
    vector<int> trace(n + 1, -1);    // lưu đỉnh trước đó để truy vết đường đi
    bf_dist[s] = 0;                  // khoảng cách từ s đến chính nó là 0

    // lặp n-1 lần để cập nhật khoảng cách ngắn nhất
    for (int i = 1; i <= n - 1; ++i) {
        for (auto [u, v, d] : edges) {
            // nếu đi từ u đến v ngắn hơn thì cập nhật
            if (bf_dist[u] != INF && bf_dist[u] + d < bf_dist[v]) {
                bf_dist[v] = bf_dist[u] + d;
                trace[v] = u; // lưu lại đường đi
            }
        }
    }

    // ghi dirty level ngắn nhất từ s đến e
    if (bf_dist[e] == INF) {
        fout << "INF\n";       // không tới được
        fout << "No path\n";
    } else {
        fout << bf_dist[e] << "\n"; // in dirty level ngắn nhất

        // truy vết đường đi từ e ngược về s
        vector<int> path;
        for (int v = e; v != -1; v = trace[v])
            path.push_back(v);

        reverseVector(path); // đảo ngược để có đường đi từ s → e

        // in đường đi
        for (int city : path)
            fout << city << " ";
        fout << "\n";
    }

    // b) Floyd warshall toàn bộ

    // khoảng cách từ i đến chính nó là 0
    for (int i = 1; i <= n; ++i)
        dist[i][i] = 0;

    // 3 vòng lặp chính của Floyd warshall
    for (int k = 1; k <= n; ++k)         // đỉnh trung gian
        for (int i = 1; i <= n; ++i)     // đỉnh bắt đầu
            for (int j = 1; j <= n; ++j) // đỉnh kết thúc
                // nếu đi qua k ngắn hơn thì cập nhật
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k]; // cập nhật đỉnh tiếp theo để truy vết đường đi
                }

    // in ma trận khoảng cách sau khi chạy Floyd ưarshall
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) fout << "INF ";
            else fout << dist[i][j] << " ";
        }
        fout << "\n";
    }

    return 0;
}
