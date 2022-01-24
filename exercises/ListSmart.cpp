#include <iostream>

using namespace std;

class Node {
public:
    Node(const int v)
        : next(nullptr),
          value(v) {}

    Node* next;
    int value;
};

class List {
public:
    List();
    ~List();
    void add(Node* node);
    Node* get(const int value);

private:
    Node* first;
};

List::List()
    : first(nullptr) {}

void List::add(Node* node) {
    if (!first) {
        first = node;
    } else {
        Node* current = first;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
    }
}

List::~List() {
    Node* current {first};
    Node* next {nullptr};
    while (current) {
        next = current->next;
        delete current;
        current = next;
    }
}

Node* List::get(const int value) {
    if (!first) {
        cout << "List is empty!" << endl;
        return nullptr;
    } else {
        Node* current = first;
        do {
            if (current->value == value) {
                cout << "Found value " << current->value << endl;
                return current;
            } else {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while (current);
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main() {
    List list;
    Node* node4 = new Node(4);
    Node* node7 = new Node(7);

    list.add(node4);
    list.add(new Node(2));
    list.add(node7);
    list.add(new Node(9));
    auto node = list.get(1);

    if (node)
        cout << node->value << '\n';

    return 0;
}
