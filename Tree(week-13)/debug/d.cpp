#include <iostream>
#include <vector>
#include <map>
#include <queue>

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

void findBottomView(Node* root) {
    if (root == nullptr) {
        return;
    }

    std::vector<int> ans;
    std::map<int, Node*> mp;
    std::queue<std::pair<Node*, int>> Q;
    Q.push({root, 0});

    while (!Q.empty()) {
        auto it = Q.front();
        Q.pop();
        Node* node = it.first;
        int col = it.second;
        mp[col] = node;
        if (node->left != nullptr)
            Q.push({node->left, col - 1});
        if (node->right != nullptr)
            Q.push({node->right, col + 1});
    }

    for (auto x : mp) {
        ans.push_back(x.second->data);
        std::cout << x.second->data << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    std::cout << "Bottom View: ";
    findBottomView(root);
    std::cout << std::endl;

    // Cleanup - deallocate memory
    // Assuming you have a function to delete the tree nodes
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
