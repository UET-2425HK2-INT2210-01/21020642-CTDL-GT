#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

const int MAXN = 100; // số máy tối đa

// cấu trúc lưu thông tin 1 cạnh: kết nối u với v, chi phí là d
struct Edge {
    int u, v, d;
};

int parent[MAXN]; // mảng lưu cha của mỗi node trong disjoint set
int setSize[MAXN];   // mảng lưu kích thước của từng tập hợp

// hàm tìm gốc của node u trong cây disjoint set
int find(int u) {
    if (parent[u] != u)
        parent[u] = find(parent[u]); // rút ngắn đường đi cho u
    return parent[u];
}

// hàm gộp 2 tập hợp chứa u và v lại, trả về true nếu gộp được
bool unite(int u, int v) {
    int pu = find(u); // tìm gốc của u
    int pv = find(v); // tìm gốc của v
    if (pu == pv) return false; // nếu cùng gốc thì ko gộp nữa

    if (setSize[pu] < setSize[pv]) swap(pu, pv); // gộp tập nhỏ vào lớn để tối ưu
    parent[pv] = pu; // nối gốc của pv vào pu
    setSize[pu] += setSize[pv]; // cập nhật size của tập mới
    return true;
}

// sắp xếp danh sách cạnh theo chi phí tăng dần
void sortEdges(vector<Edge>& edges) {
    for (int i = 0; i < edges.size(); ++i)
        for (int j = i + 1; j < edges.size(); ++j)
            if (edges[i].d > edges[j].d)
                swap(edges[i], edges[j]); // nếu cạnh sau có chi phí nhỏ hơn thì swapp
}

int main() {
    ifstream fin("connection.txt");  // mở file input
    ofstream fout("connection.out"); // mở file output

    int n, m;
    fin >> n >> m; // đọc số lượng máy tính và số kết nối có thể

    vector<Edge> edges(m); // danh sách các cạnh (kết nối)

    // đọc thông tin từng cạnh: 2 đầu mối và chi phí
    for (int i = 0; i < m; ++i)
        fin >> edges[i].u >> edges[i].v >> edges[i].d;

    // khởi tạo disjoint set: mỗi máy là 1 tập riêng, gốc chính nó
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        setSize[i] = 1;
    }

    sortEdges(edges); // sắp xếp cạnh theo chi phí tăng dần

    int totalCost = 0;         // biến lưu tổng chi phí
    vector<Edge> mst;          // lưu các cạnh được chọn vào cây khung

    // lặp qua từng cạnh đã sắp
    for (auto edge : edges) {
        if (unite(edge.u, edge.v)) {
            totalCost += edge.d;  // cộng chi phí
            mst.push_back(edge);  // thêm cạnh vào cây
        }
    }

    fout << totalCost << "\n"; // ghi tổng chi phí ra file

    // ghi danh sách các cạnh được chọn
    for (auto edge : mst)
        fout << edge.u << " " << edge.v << " " << edge.d << "\n";

    return 0;
}
