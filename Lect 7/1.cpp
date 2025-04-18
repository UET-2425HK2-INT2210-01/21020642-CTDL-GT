#include <iostream>
#include <fstream>
using namespace std;

#include <sstream> // dùng để tạo chuỗi
#include <string>

string printArray(int arr[], int n) {
    ostringstream oss;
    for (int i = 0; i < n; ++i) {
        oss << arr[i];
        if (i < n - 1) oss << " ";
    }
    return oss.str();
}


void bubbleSort(int numbers[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) { // chạy 2 vòng for 
            if (numbers[j] > numbers[j + 1]) {
                swap(numbers[j], numbers[j + 1]); // đổi chỗ 2 phần tử nếu phần tử trước lớn hơn phần tử sau
            }
        }
    }
};


int main() {
    ifstream inputFile("numbers.txt"); // mở file numbers.txt
    if (!inputFile) { 
        cerr << "Error opening file." << endl;
        return  {}; 
    }

    ofstream outputFile("numbers.sorted"); // mở file đầu ra 
    if (!outputFile) {
        cerr << "Không thể mở file đầu ra." << endl;
        return 1;
    }


    int numbers[100];
    int count = 0;

    while (inputFile >> numbers[count]) { // đếm số lượng phần tử trong file
        count++;
    }
    inputFile.close();

    bubbleSort(numbers, count); // sắp xếp mảng bằng bubble sort
    outputFile << printArray(numbers, count); // in ra mảng đã sắp xếp

    return 0;
}