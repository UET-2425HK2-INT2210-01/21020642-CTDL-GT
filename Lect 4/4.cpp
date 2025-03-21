#include <iostream>
#include <list>
#include <sstream>
using namespace std;

struct Student {
    int ID;
    string Name;
    string Class;

    Student(int ID, string Name, string Class) {
        this->ID = ID;
        this->Name = Name;
        this->Class = Class;
    }

    string information (bool containID) {
        return (containID ? to_string(ID) + ", " : "") + Name + ", " + Class;
    }
};

struct HashTable {
    int capacity;
    list<Student> *table;

    HashTable(int capacity){
        this->capacity = capacity;
        table = new list<Student>[this->capacity];
    }

    int hashFunction (int key) {
        return ((key * key + 2 * key + 1) % this->capacity);
    }

    void insertStudent (int ID, string Name, string Class) {
        int index = hashFunction(ID);
        Student* tmp = new Student(ID, Name, Class);
        table[index].push_back(*tmp);
    }

    void removeStudent (int ID) {
        int index = hashFunction(ID);
        list<Student>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if ((*i).ID == ID) {
                break;
            }
        }
        if (i != table[index].end()) {
            table[index].erase(i);
        }
    }

    void print() {
        for (int j = 0; j < this->capacity; j++) {
            string tmp = to_string(j);
            if (table[j].size() != 0) {
                list<Student>::iterator i;
                for (i = table[j].begin(); i != table[j].end(); i++) {
                    tmp += " <-- " + (*i).information(true);
                }
            }

            cout << tmp << endl;
        }
    }
    
    void infor(int ID) {
        int index = hashFunction(ID);
        list<Student>::iterator i;
        for (i = table[index].begin(); i != table[index].end(); i++) {
            if ((*i).ID == ID) {
                break;
            }
        }
        if (i != table[index].end()) {
            cout << (*i).information(false) << endl;
        } else {
            cout << "NA, NA" << endl;
        }
    }
};



int main() {
    HashTable* ht = new HashTable(10);
    string command;
    while (getline(cin, command)) {
        if (command.substr(0, 6) == "Insert") {
            int id;
            string name, className;
            sscanf(command.c_str(), "Insert(%d,", &id);

            size_t firstComma = command.find(',', 7); 
            size_t secondComma = command.find(',', firstComma + 1);
            size_t closeParen = command.find(')', secondComma + 1);

            name = command.substr(firstComma + 1, secondComma - firstComma - 1);
            className = command.substr(secondComma + 1, closeParen - secondComma - 1);

            name.erase(0, name.find_first_not_of(" \t"));
            name.erase(name.find_last_not_of(" \t") + 1);
            className.erase(0, className.find_first_not_of(" \t"));
            className.erase(className.find_last_not_of(" \t") + 1);

            ht->insertStudent(id, name, className);
        }
        else if (command.substr(0, 6) == "Delete") {
            int id;
            sscanf(command.c_str(), "Delete(%d)", &id);
            ht->removeStudent(id);
        }
        else if (command.substr(0, 5) == "Infor") {
            int id;
            sscanf(command.c_str(), "Infor(%d)", &id);
            ht->infor(id);
        }
        else if (command == "Print") { 
            ht->print();
        }
    }

    return 0;
}
