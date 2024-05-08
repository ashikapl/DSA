// Inorder Successor
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

Node* inorderSucc(Node* root, Node* s)
{
    Node* succ = 0;
    Node* curr = root;

    while(curr)
    {
        if(curr->data > s->data)
        {
            succ = curr;
            curr = curr->left;
        }
        else
        {
            curr = curr->right;
        }
    }

    return succ;
}

int main()
{
    // Construct the binary search tree
    Node* root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(8);
    root->left->left = new Node(2);
    root->left->right = new Node(4);
    root->right->left = new Node(7);
    root->right->right = new Node(9);

    // Find the inorder successor of a node
    Node* node = root->left->left; // Example node to find its inorder successor
    Node* succ = inorderSucc(root, node);
    if (succ)
        cout << "Inorder successor of " << node->data << " is " << succ->data << endl;
    else
        cout << "No inorder successor found for " << node->data << endl;

    return 0;
}