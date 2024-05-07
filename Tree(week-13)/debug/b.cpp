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

void preorderTraversal(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->data << " ";
    for (int i = 0; i < node->children.size(); i++) {
        preorderTraversal(node->children[i]);
    }
}

int main() {
    Node* root = new Node(1);

    Node* child1 = new Node(2);
    Node* child2 = new Node(3);
    Node* child3 = new Node(4);

    root->addChild(child1);
    root->addChild(child2);
    root->addChild(child3);

    std::cout << "Preorder Traversal: ";
    preorderTraversal(root);
    std::cout << std::endl;

    // Clean up - deallocate memory
    delete root;
    delete child1;
    delete child2;
    delete child3;

    return 0;
}