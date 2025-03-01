#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* prev;
    Node* next;
    
    // construction
    Node() {}
    Node(int v, Node* p, Node* n) {
        value = v;
        prev = p;
        next = n;
    }
};

class DoublyLinkedList {
    Node* head;

public:
    // construction
    DoublyLinkedList() {
        head = NULL;
    }
    DoublyLinkedList(Node* h) {
        head = h;
    }
    
    // insert
    void insertBack(int value) {
        if (head == NULL) {
            head = new Node(value, NULL, NULL);
        } else {
            Node* p = head;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = new Node(value, p, NULL);
        }
    }
    
    // Print List
    void print () {
        Node* p = head;
        while (p != NULL) {
            cout << p->value << ' ';
            p = p->next;
        }
        cout << endl;
    }
    
    // Count Nodes
    int countNodes () {
        int res = 0;
        Node* p = head;
        while (p != NULL) {
            p = p->next;
            res ++;
        }
        
        return res;
    }
    
    // Count triplets
    int countTriplets () {
        if (this->countNodes() < 3) {
            return 0;
        }
        int res = 0;
        Node* p = head;
        while(p->next->next != NULL) {
            if (p->value + p->next->value + p->next->next->value == 0) {
                res ++;
            }
            p = p->next;
        }
        
        return res;
    }
};

DoublyLinkedList* inputDoublyLinkedList (int n) {
    DoublyLinkedList* res = new DoublyLinkedList();
    for (int i = 0; i < n; i ++) {
        int tmp;
        cin >> tmp;
        res->insertBack(tmp);
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    DoublyLinkedList* l = inputDoublyLinkedList(n);
    cout << l->countTriplets() << endl;
    
    return 0;
}