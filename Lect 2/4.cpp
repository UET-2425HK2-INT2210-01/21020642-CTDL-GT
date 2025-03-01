#include <iostream>
using namespace std;

void deleteFirstEleInArr (int* A, int& n) {
    for (int i = 0; i < n - 1; i ++) {
        A[i] = A[i + 1];
    }
    n --;
}

class Queue {
    int* values;
    int countValue;
    
public:
    // Construction & destruction
    Queue() {
        values = new int[100];
        countValue = 0;
    }
    ~Queue() {
        delete [] values;
    }
    
    // Print
    void printQueue() {
        for (int i = 0; i < countValue; i ++) {
            cout << values[i] << ' ';
        }
        cout << endl;
    }
    
    // Enqueue & dequeue
    void enqueue(int value) {
        values[countValue] = value;
        countValue ++;
    }
    void dequeue() {
        deleteFirstEleInArr(values, countValue);
    }
};

int main() {
    Queue myQueue;

    myQueue.enqueue(1);
    myQueue.enqueue(2);
    myQueue.enqueue(3);
    myQueue.enqueue(4);
    myQueue.dequeue();
    myQueue.dequeue();
    myQueue.enqueue(5);
    myQueue.printQueue();

    return 0;
}