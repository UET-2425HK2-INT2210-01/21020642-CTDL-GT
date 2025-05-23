#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

// topo_sort_jobs
vector<int> topo_sort_jobs(int n, const vector<vector<int>>& adj, vector<int> indegree) {
    queue<int> q;
    vector<int> result;

    // đẩy các job ko bị phụ thuộc vào hàng đợi
    for (int i = 1; i <= n; ++i)
        if (indegree[i] == 0) q.push(i);

    while (!q.empty()) {
        int u = q.front(); q.pop(); // lấy 1 job có thể làm được ra
        result.push_back(u);        // thêm vào kết quả

        for (int v : adj[u]) {
            indegree[v]--;          // u xong rồi nên v giảm bậc vào
            if (indegree[v] == 0) q.push(v); // nếu v ko còn phụ thuộc thì thêm vào hàng đợi
        }
    }

    return result; // trả về thứ tự thực hiện các job
}

int main() {
    ifstream fin("jobs.txt");
    ofstream fout("jobs.out");

    int n, m;
    fin >> n >> m; // số lượng job và số ràng buộc

    vector<vector<int>> adj(n + 1); // danh sách kề
    vector<int> indegree(n + 1, 0); // bậc vào

    // đọc m dòng ràng buộc u trước v
    for (int i = 0; i < m; ++i) {
        int u, v;
        fin >> u >> v;
        adj[u].push_back(v);   // v phụ thuộc u
        indegree[v]++;         // tăng bậc vào của v
    }

    // gọi hàm sắp xếp topo
    vector<int> result = topo_sort_jobs(n, adj, indegree);

    // nếu ko sắp được hết n job thì có chu trình
    if ((int)result.size() != n) {
        fout << "Invalid: Cycle detected\n";
    } else {
        for (int job : result)
            fout << job << " ";
        fout << "\n";
    }

    return 0;
}
