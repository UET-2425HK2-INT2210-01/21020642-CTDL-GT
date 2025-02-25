// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
#include <string>

int main() {
    string word;
    cout << "Enter your sentence: ";
    getline(cin, word);
    
    cout << "This is your sentence in reversed order: ";
    for (int i = word.length()-1; i>=0; i--) {
        cout << word[i];
    }

    return 0;
}