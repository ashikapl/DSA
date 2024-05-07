#include <iostream>
#include <map>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    int hd; // horizontal distance
    Node* left;
    Node* right;

    Node(int value) : data(value), hd(0), left(nullptr), right(nullptr) {}
};

void topview(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    map<int, int> m;

    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        int hd = current->hd;
        if (m.count(hd) == 0)
            m[hd] = current->data;

        if (current->left != nullptr) {
            current->left->hd = hd - 1;
            q.push(current->left);
        }
        if (current->right != nullptr) {
            current->right->hd = hd + 1;
            q.push(current->right);
        }
    }

    for (auto it = m.begin(); it != m.end(); ++it) {
        cout << it->second << " ";
    }
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    cout << "Top View: ";
    topview(root);
    cout << endl;

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
