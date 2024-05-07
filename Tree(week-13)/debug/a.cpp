#include <iostream>
#include <vector>

class Node {
public:
    int data;
    std::vector<Node*> children;

    Node(int value) : data(value) {}

    void addChild(Node* child) {
        children.push_back(child);
    }
};

int main() {
    Node root(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);

    root.addChild(child1);
    root.addChild(child2);

    std::cout << "Root Node: " << root.data << std::endl;
    std::cout << "Children: ";
    for (auto child : root.children) {
        std::cout << child->data << " ";
    }
    std::cout << std::endl;

    // Cleanup - deallocate memory
    delete child1;
    delete child2;

    return 0;
}