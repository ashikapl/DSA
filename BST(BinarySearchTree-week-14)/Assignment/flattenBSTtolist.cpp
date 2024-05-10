// Flatten BST to a sorted linked list
#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};
void inorder(Node* root, Node* &prev)
{    
    if(!root) return;
        
    inorder(root->left,prev);
        
    prev->left = NULL;
    prev->right = root;
    prev = root;
        
    inorder(root->right,prev);
}

Node *flattenBST(Node *root)
{
    Node* dummy = new Node(-1);
    Node* prev = dummy;
    inorder(root,prev);
    prev->left = prev->right = NULL;
    root = dummy->right;
    delete dummy;
    return root;
}

// Function to print the flattened linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}

int main() {
    // Create a sample binary search tree
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->right->left = new Node(5);
    root->right->right = new Node(7);

    // Flatten the binary search tree
    Node* flattenedList = flattenBST(root);

    // Print the flattened linked list
    cout << "Flattened Linked List: ";
    printList(flattenedList);

    // Clean up memory
    delete root; // Ensure to delete the entire tree

    return 0;
}

