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
    void add(std::shared_ptr<Node> node);
    std::shared_ptr<Node> get(const int value);

private:
    std::shared_ptr<Node> first;
};

List::List()
    : first(nullptr) {}

void List::add(std::shared_ptr<Node> node) {
    if (!first) {
        first = node;
    } else {
        std::shared_ptr<Node> current = first;
        while (current->next) {
            current = current->next;
        }
        current->next = node;
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
    auto node4 = std::make_shared<Node>(4);
    auto node7 = std::make_shared<Node>(7);

    list.add(node4);
    list.add(std::make_shared<Node>(2));
    list.add(node7);
    list.add(std::make_shared<Node>(9));
    try {
        auto node = list.get(1);
        if (node)
            cout << node->value << '\n';
    } catch (const EmptyListError& exception) {
        std::cout << "ERROR: " << exception.what() << std::endl;
        return 0;
    }
}
