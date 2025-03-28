#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* firstChild;
    Node* nextSibling;

    // Hàm khởi tạo
    Node(int data) : data(data), firstChild(nullptr), nextSibling(nullptr) {}
};

class Tree {
    
public:
    Node* root;

    // Hàm khởi tạo
    Tree() : root(nullptr) {}

    //Hàm huỷ
    ~Tree() {
        destroyTree(root);
    }

    // Hàm giải phóng bộ nhớ cho cây
    void destroyTree(Node* node) {
        if (node == nullptr) return;         // Nếu node rỗng, không cần giải phóng

        Node* child = node->firstChild;
        while (child != nullptr) {           // Duyệt qua các node con
            Node* next = child->nextSibling; // Lưu node anh em kế tiếp trước khi giải phóng child
            destroyTree(child);              // Gọi đệ quy để giải phóng node con
            child = next;                    // Di chuyển đến node anh em kế tiếp
        }
        delete node;                         // Giải phóng node hiện tại
    }


    // Hàm tính chiều cao cả cây
    int height() { 
        return height(root); 
    }

    // Hàm tính chiều cao của một node cụ thể
    int height(Node* node) {
        if (node == nullptr) return 0;       // Cây rỗng thì chiều cao = 0

        int maxHeight = 0;
        Node* child = node->firstChild;
        while (child != nullptr) {           // Duyệt qua các node con
            maxHeight = max(maxHeight, height(child)); // Tính chiều cao của cây con và cập nhật maxHeight
            child = child->nextSibling;      // Di chuyển đến node anh em kế tiếp
        }

        return maxHeight + 1;                // Chiều cao của node hiện tại = chiều cao lớn nhất của cây con + 1
    }

    // Hàm duyệt cây theo preorder
    void preorder() {
        preorder(root); cout << endl;
    }

    void preorder(Node* node) {
        if (node == nullptr) return;         // Nếu node rỗng, do nothing

        cout << node->data << " ";           // In ra node hiện tại
        Node* child = node->firstChild;
        while (child != nullptr) {           // Duyệt qua các node con
            preorder(child);                 // Gọi đệ quy để duyệt cây con
            child = child->nextSibling;      // Di chuyển đến node anh em kế tiếp
        }
    }

    // Hàm duyệt cây theo postorder
    void postorder() { 
        postorder(root); cout << endl;
    }
    
    void postorder(Node* node) {
        if (node == nullptr) return;         // Nếu node rỗng, không làm gì cả

        Node* child = node->firstChild;
        while (child != nullptr) {           // Duyệt qua các node con
            postorder(child);                // Gọi đệ quy để duyệt cây con
            child = child->nextSibling;      // Di chuyển đến node anh em kế tiếp
        }
        cout << node->data << " ";           // In ra node hiện tại
    }

    // Hàm kiểm tra xem cây có phải là cây nhị phân không
    bool isBinaryTree(Node* node) {
        if (node == nullptr) return true;    // Cây rỗng là cây nhị phân

        int childCount = 0;
        Node* child = node->firstChild;
        while (child != nullptr) {           // Đếm số lượng node con
            childCount++;
            child = child->nextSibling;      // Di chuyển đến node anh em kế tiếp
        }

        if (childCount > 2) return false;    // Nếu có node > 2 con, không phải cây nhị phân

        child = node->firstChild;
        while (child != nullptr) {           // Duyệt qua các node con
            if (!isBinaryTree(child)) return false; // Kiểm tra đệ quy các cây con
            child = child->nextSibling;      // Di chuyển đến node anh em kế tiếp
        }

        return true;                         // Nếu tất cả các node đều có <= 2 con, thì là cây nhị phân
    }

    // Hàm duyệt cây theo thứ tự giữa inorder - chỉ dùng được cho cây nhị phân
    void inorder() { 
        vector<int> result; inorder(root, result);  for(int node : result) cout << node << " "; cout << endl;
    }
    
    void inorder(Node* node, vector<int>& result) {
        if (node == nullptr) return;

        Node* child = node->firstChild;
        int childCount = 0;
        while(child != nullptr)
        {
            childCount++;
            child = child->nextSibling;
        }

        if(childCount == 0) {
            result.push_back(node->data);
            return;
        }

        child = node->firstChild;            // Reset

        if (childCount == 1) {
            inorder(child, result);
            result.push_back(node->data);
            return;
        }
        else if (childCount == 2) {
            Node* leftChild = node->firstChild;
            Node* rightChild = leftChild->nextSibling;

            inorder(leftChild, result);
            result.push_back(node->data);
            inorder(rightChild, result);
            return;
        }
    }

};

int main() {
    int n, m;                                // Số lượng node và số lượng cạnh
    cin >> n >> m;

    Node* nodes[n];                          // Mảng các node để lưu trữ các node đã tạo
    for (int i = 0; i < n; ++i) {
        nodes[i] = new Node(i + 1);          // Tạo các node và lưu vào mảng
    }

    Tree myTree;                             // Tạo một đối tượng myTree
    vector<bool> isChild(n, false);          // Mảng để đánh dấu node nào là con của node khác

    for (int i = 0; i < m; ++i) {
        int u, v;                            // u là cha của v
        cin >> u >> v;

        Node* parent = nodes[u - 1];         // Lấy node cha từ mảng
        Node* child = nodes[v - 1];          // Lấy node con từ mảng
        isChild[v - 1] = true;               // Đánh dấu node v là con

        // Thêm child vào danh sách con của parent
        if (parent->firstChild == nullptr) {
            parent->firstChild = child;      // Nếu parent chưa có con, thì child là con đầu tiên
        } else {
            Node* sibling = parent->firstChild;
            while (sibling->nextSibling != nullptr) {  // Tìm node anh em cuối cùng
                sibling = sibling->nextSibling;
            }
            sibling->nextSibling = child;    // Thêm child vào cuối danh sách anh em
        }
    }

    // Tìm node gốc (node không phải là con của ai)
    for (int i = 0; i < n; ++i) {
        if (!isChild[i]) {                   // Nếu node không phải là con của ai cả
            myTree.root = nodes[i];          // Gán node này làm node gốc của cây
            break;
        }
    }

    cout << myTree.height() << endl;

    myTree.preorder();

    myTree.postorder();

    if (myTree.isBinaryTree(myTree.root)) { // Kiểm tra xem cây có phải là cây nhị phân không
        myTree.inorder();
    } else {
        cout << "NOT BINARY TREE" << endl;
    }

    // Giải phóng bộ nhớ trước khi kết thúc
    for (int i = 0; i < n; ++i) {
        delete nodes[i]; // Giải phóng từng node
    }

    return 0;
}