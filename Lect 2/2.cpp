#include <iostream>
#include <string>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int v, Node* n = NULL) : value(v), next(n) {}
};

class SinglyLinkedList {
    Node* head;
    int countNode;

public:
    SinglyLinkedList() : head(NULL), countNode(0) {}

    void print() {
        Node* p = head;
        while (p != NULL) {
            cout << p->value << ' ';
            p = p->next;
        }
        cout << endl;
    }

    void insertNode(int pos, int x) {
        if (pos > countNode) return;
        
        Node* newNode = new Node(x);
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* p = head;
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
            }
            newNode->next = p->next;
            p->next = newNode;
        }
        countNode++;
    }

    void deleteNode(int pos) {
        if (pos >= countNode || head == NULL) return;
        
        Node* p = head;
        if (pos == 0) {
            head = head->next;
            delete p;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                p = p->next;
            }
            Node* tmp = p->next;
            p->next = tmp->next;
            delete tmp;
        }
        countNode--;
    }
};

int main() {
    int n;
    string line;
    getline(cin, line);
    n = stoi(line);
    
    SinglyLinkedList list;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        string op;
        int p, x;
        
        size_t space1 = line.find(' ');
        op = line.substr(0, space1);
        line = line.substr(space1 + 1);
        
        size_t space2 = line.find(' ');
        p = stoi(line.substr(0, space2));
        
        if (op == "insert") {
            x = stoi(line.substr(space2 + 1));
            list.insertNode(p, x);
        } else if (op == "delete") {
            list.deleteNode(p);
        }
        // list.print();
    }
    list.print();

    return 0;
}
