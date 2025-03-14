#include <iostream>
using namespace std;

struct Node {   
    int data;  
    Node* next;
    Node(int d, Node* n = NULL) : data(d), next(n) {}
};

class LinkedList {    
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {};

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
    

    void append(int data) {
        if (head == nullptr) {
            head = new Node(data);
        } else {
            Node* p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = new Node(data);
        } 
    }

    string print() {
        if (head == nullptr){
            return "Your LinkedList is empty!\n";
        } else {
            Node* temp = head;
            string output = "";
            while (temp != nullptr) {
                output += to_string(temp->data) + " ";
                temp = temp->next;
            }
            return output + "\n";
        }
    }

    string search(int data) {
        if (head == nullptr) {
            return "Your Linked list is empty!\n";
        }
        else {
            Node* temp = head;
            int index = 0;
            while (temp != nullptr) {
                if (temp->data == data) {
                    return to_string(index) + "\n";
                }
                index++;
                temp = temp->next;
            }
            return "NO\n";
        }
    }

    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node * next = nullptr;
        while (current != nullptr) {
            next = current->next; 
            current->next = prev; 
            prev = current;       
            current = next;       
        }
        head = prev;
    }
    
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    
    LinkedList myList;
    string output = "";
    
    string line;
    for (int i = 0; i < n; i++) {
        getline(cin, line);
        string op;
        int x;
        
        size_t space = line.find(' ');
        op = line.substr(0, space);
        
        if (op == "append") {
            x = stoi(line.substr(space + 1));
            myList.append(x);
        } 
        if (op == "search") {
            output += myList.search(x);
        }
        if (op == "reverse") {
            myList.reverse();
            output += myList.print();
        }
        if (op == "print") {
            output += myList.print();
        }
    }
    cout << output;
}