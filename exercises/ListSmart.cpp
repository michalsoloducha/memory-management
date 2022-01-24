#include <iostream>
#include <memory>
#include "EmptyListError.hpp"

using namespace std;

class Node {
public:
    Node(const int v)
        : next(nullptr),
          value(v) {}

    std::shared_ptr<Node> next;
    int value;
};

class List {
public:
    List();
    void add(const int);
    std::shared_ptr<Node> get(const int);

private:
    std::shared_ptr<Node> first;
};

List::List()
    : first(nullptr) {}

void List::add(const int value) {
    if (!first) {
        first = std::make_shared<Node>(value);
    } else {
        std::shared_ptr<Node> current = first;
        while (current->next) {
            current = current->next;
        }
        current->next = std::make_shared<Node>(value);
    }
}

std::shared_ptr<Node> List::get(const int value) {
    if (!first) {
        cout << "List is empty!" << endl;
        return nullptr;
    } else {
        std::shared_ptr<Node> current = first;
        do {
            if (current->value == value) {
                cout << "Found value " << current->value << endl;
                return current;
            } else {
                cout << "Going through " << current->value << endl;
                current = current->next;
            }
        } while (current);
        throw EmptyListError("List element not found");
        return nullptr;
    }
}

int main() {
    List list;

    list.add(4);
    list.add(2);
    list.add(7);
    list.add(9);
    list.add(4);
    try {
        auto node = list.get(1);
        if (node)
            cout << node->value << '\n';
    } catch (const EmptyListError& exception) {
        std::cout << "ERROR: " << exception.what() << std::endl;
        return 0;
    }
}
