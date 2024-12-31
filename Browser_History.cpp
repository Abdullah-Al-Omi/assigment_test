#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string site;
    Node* next;
    Node* prev;

    Node(string site) {
        this->site = site;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    Node* head;
    Node* tail;
    Node* current;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void insert_at_tail(string site) {
        Node* newNode = new Node(site);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
            current = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void visit(string site) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->site == site) {
                current = temp;
                cout << "Visited: " << site << endl;
                return;
            }
            temp = temp->next;
        }
        // If site not found, insert at tail and update current
        insert_at_tail(site);
        current = tail;
        cout << "Visited: " << site << endl;
    }

    void prev() {
        if (current != nullptr && current->prev != nullptr) {
            current = current->prev;
            cout << "Visited: " << current->site << endl;
        } else {
            cout << "NotAvailable" << endl;
        }
    }

    void next() {
        if (current != nullptr && current->next != nullptr) {
            current = current->next;
            cout << "Visited: " << current->site << endl;
        } else {
            cout << "NotAvailable" << endl;
        }
    }
};

int main() {
    DoublyLinkedList dll;
    string input;

    while (true) {
        getline(cin, input);
        if (input == "end") {
            break;
        }
        if (input == "-1") {
            continue;
        }
        dll.insert_at_tail(input);
    }

    while (true) {
        getline(cin, input);
        if (input == "end") {
            break;
        }
        size_t commaPos = input.find(',');
        string command = input.substr(0, commaPos);
        if (command == "visit") {
            string site = input.substr(commaPos + 1);
            dll.visit(site);
        } else if (command == "prev") {
            dll.prev();
        } else if (command == "next") {
            dll.next();
        }
    }

    return 0;
}