#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedList {
public:
    list<string> dll;
    unordered_map<string, list<string>::iterator> addressMap;
    list<string>::iterator current;

    DoublyLinkedList() {
        current = dll.end();
    }

    void insert_at_tail(string site) {
        dll.push_back(site);
        addressMap[site] = --dll.end();
        if (current == dll.end()) {
            current = dll.begin();
        }
    }

    void visit(string site) {
        if (addressMap.find(site) != addressMap.end()) {
            current = addressMap[site];
            cout << *current << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void next() {
        if (current != dll.end() && next(current) != dll.end()) {
            ++current;
            cout << *current << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }

    void prev() {
        if (current != dll.begin()) {
            --current;
            cout << *current << endl;
        } else {
            cout << "Not Available" << endl;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    string input;

    // Read the initial list of addresses
    while (true) {
        cin >> input;
        if (input == "end") {
            break;
        }
        dll.insert_at_tail(input);
    }

    int Q;
    cin >> Q;
    cin.ignore(); // Ignore the newline character after the integer input

    // Process the queries
    for (int i = 0; i < Q; ++i) {
        getline(cin, input);
        size_t spacePos = input.find(' ');
        string command = input.substr(0, spacePos);

        if (command == "visit") {
            string site = input.substr(spacePos + 1);
            dll.visit(site);
        } else if (command == "next") {
            dll.next();
        } else if (command == "prev") {
            dll.prev();
        }
    }

    return 0;
}