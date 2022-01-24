#include <iostream>
#include <memory>

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
        cout << "Not found: value " << value << endl;
        return nullptr;
    }
}

int main() {
    List list;
    std::shared_ptr<Node> node4 = std::make_shared<Node>(Node(4));
    std::shared_ptr<Node> node7 = std::make_shared<Node>(Node(7));

    list.add(node4);
    list.add(std::make_shared<Node>(Node(2)));
    list.add(node7);
    list.add(std::make_shared<Node>(Node(9)));
    list.add(node4);
    auto node = list.get(1);

    if (node)
        cout << node->value << '\n';

    return 0;
}
