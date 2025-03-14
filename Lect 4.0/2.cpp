#include <iostream>
using namespace std;

struct Node {
    int data, priority;
    Node* next;
    Node* prev;
    Node(int d, int p) : data(d), priority(p), next(nullptr), prev(nullptr) {}
};

class PriorityQueue {
private:
    Node* head;

public:
    PriorityQueue() : head(nullptr) {}

    ~PriorityQueue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(int data, int priority) {
        Node* newNode = new Node(data, priority);
        if (!head || head->priority < priority) {
            newNode->next = head;
            if (head) head->prev = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next && temp->next->priority >= priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next) temp->next->prev = newNode;
            temp->next = newNode;
        }
    }

    void dequeue() {
        if (!head) return;
        Node* temp = head;
        head = head->next;
        if (head) head->prev = nullptr;
        delete temp;
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << "(" << temp->data << ", " << temp->priority << ")";
            if (temp->next) cout << "; ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    PriorityQueue pq;
    string op;
    
    for (int i = 0; i < n; i++) {
        getline(cin, op);
        if (op.substr(0, 7) == "enqueue") {
            int x, p;
            sscanf(op.c_str(), "enqueue %d %d", &x, &p);
            pq.enqueue(x, p);
        } else if (op == "dequeue") {
            pq.dequeue();
        }
    }
    
    pq.print();
    return 0;
}
