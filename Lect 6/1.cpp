#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// tạo node mới
Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

// thêm phần tử vào BST
Node* insert(Node* root, int value) {
    if (root == nullptr) return createNode(value); // nếu rỗng thì tạo node mới
    if (value < root->data) root->left = insert(root->left, value); // chèn bên trái nếu nhỏ hơn
    else root->right = insert(root->right, value); // chèn bên phải nếu lớn hơn hoặc bằng
    return root;
}

// tìm node nhỏ nhất bên phải (trái nhất của cây con phải)
Node* findMin(Node* root) {
    while (root && root->left != nullptr) root = root->left; // đi đến node trái cùng
    return root;
}

// xóa phần tử trong BST
Node* deleteNode(Node* root, int value) {
    if (root == nullptr) return root; // ko tìm thấy
    if (value < root->data) root->left = deleteNode(root->left, value); // tìm bên trái
    else if (value > root->data) root->right = deleteNode(root->right, value); // tìm bên phải
    else {
        // case 1: không có con trái
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        // case 2: không có con phải
        if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        // case 1 + case 2 đồng thời giải quyết luôn TH 0 có con nào hết
        // case 3: có 2 con -> thay bằng node nhỏ nhất bên phải
        Node* temp = findMin(root->right);
        root->data = temp->data; // gán giá trị nhỏ nhất
        root->right = deleteNode(root->right, temp->data); // xóa node đã thaythay
    }
    return root;
}

// duyệt cây theo inorder (trái - chacha - phải)
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    Node* root = nullptr;

    // ban đầu
    for (int i = 0; i < 9; ++i) root = insert(root, values[i]);
    cout << "BST: ";
    inorder(root);
    cout << endl;

    // chèn thêm phần tử 
    int addVals[] = {14, 0, 35};
    for (int i = 0; i < 3; ++i) root = insert(root, addVals[i]);
    cout << "BST after inserting: ";
    inorder(root);
    cout << endl;

    // xóa phần tử
    int delVals[] = {6, 13, 35};
    for (int i = 0; i < 3; ++i) root = deleteNode(root, delVals[i]);
    cout << "BST after deleting: ";
    inorder(root);
    cout << endl;

    return 0;
}
