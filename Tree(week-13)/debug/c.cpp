#include <iostream>
#include <vector>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void mirror(Node* node) {
    if (node == nullptr) return;
    mirror(node->left);
    mirror(node->right);
    std::swap(node->left, node->right);
}

void printInOrder(Node* node) {
    if (node == nullptr) return;
    printInOrder(node->left);
    std::cout << node->data << " ";
    printInOrder(node->right);
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    std::cout << "Original tree (in-order traversal): ";
    printInOrder(root);
    std::cout << std::endl;

    mirror(root);

    std::cout << "Mirrored tree (in-order traversal): ";
    printInOrder(root);
    std::cout << std::endl;

    // Cleanup - deallocate memory
    // Assuming you have a function to delete the tree nodes
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
