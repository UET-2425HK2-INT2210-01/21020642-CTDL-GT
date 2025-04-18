#include <iostream>
using namespace std;

const int MAX = 100;
int heap[MAX]; // mảng heapheap
int heapSize = 0;

// đổi chỗ
void swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

// thêm phần tử vào heap
void insertHeap(int value) {
    // tăng kích thước heap và gán giá trị mới vào cuối mảng
    heap[++heapSize] = value;

    int i = heapSize;
    // duyệt lên phía trên để đảm bảo tính chất max heap
    while (i > 1 && heap[i] > heap[i / 2]) {
        // nếu giá trị hiện tại lớn hơn cha thì đổi chỗ
        swap(heap[i], heap[i / 2]);
        // tiếp tục kiểm tra với cha ở cấp cao hơn
        i = i / 2;
    }
}

// đẩy phần tử lớn nhất xuống đúng vị trí
void heapify(int i) {
    // tính index con trái và con phải
    int left = 2 * i;
    int right = 2 * i + 1;
    int largest = i;

    // nếu con trái tồn tại và lớn hơn cha thì gán largest = con trái
    if (left <= heapSize && heap[left] > heap[largest]) largest = left;
    // nếu con phải tồn tại và lớn hơn giá trị lớn nhất hiện tại thì cập nhật
    if (right <= heapSize && heap[right] > heap[largest]) largest = right;

    // nếu cần hoán đổi thì đổi chỗ và gọi đệ quy xuống nhánh bị thay đổi
    if (largest != i) {
        swap(heap[i], heap[largest]);
        heapify(largest);
    }
}

// xóa một phần tử khỏi heap
void deleteValue(int value) {
    int index = -1;

    // tìm vị trí của phần tử cần xóaxóa trong mảng heap
    for (int i = 1; i <= heapSize; ++i) {
        if (heap[i] == value) {
            index = i;
            break;
        }
    }

    // nếu không tìm thấy thì return luôn
    if (index == -1) return;

    // thay phần tử cần xóa bằng phần tử cuối cùng trong heap
    heap[index] = heap[heapSize--];

    // gọi heapify để sắp xếp lại từ vị trí bị thay đổi
    heapify(index);
}


// in heap
void printHeap() {
    for (int i = 1; i <= heapSize; ++i)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int values[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    for (int i = 0; i < 9; ++i) insertHeap(values[i]);
    cout << "Heap: ";
    printHeap();

    int addVals[] = {14, 0, 35};
    for (int i = 0; i < 3; ++i) insertHeap(addVals[i]);
    cout << "Heap after inserting: ";
    printHeap();

    int delVals[] = {6, 13, 35};
    for (int i = 0; i < 3; ++i) deleteValue(delVals[i]);
    cout << "Heap after deleting: ";
    printHeap();

    return 0;
}
