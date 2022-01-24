#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>

struct EmptyListError : std::runtime_error {
    EmptyListError()
        : std::runtime_error("ERROR: List is empty!") {}
};

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
        throw EmptyListError();
    } else {
        std::shared_ptr<Node> current = first;
        do {
            if (current->value == value) {
                std::cout << "Found value " << current->value << std::endl;
                return current;
            } else {
                std::cout << "Going through " << current->value << std::endl;
                current = current->next;
            }
        } while (current);
        std::cout << "Not found: value " << value << std::endl;
        return nullptr;
    }
}

int main() {
    List list;

    try {
        auto node = list.get(1);
        if (node)
            std::cout << node->value << '\n';
    } catch (const EmptyListError& exception) {
        std::cerr << exception.what() << std::endl;
    }

    list.add(4);
    list.add(2);
    list.add(7);
    list.add(9);
    list.add(4);

    try {
        auto node = list.get(1);
        if (node)
            std::cout << node->value << '\n';
    } catch (const EmptyListError& exception) {
        std::cerr << exception.what() << std::endl;
    }
}
