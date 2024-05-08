// Inorder Predecessor
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

Node* inorderPred(Node*root,Node*p)
{
    Node* pred = 0;
    Node* curr = root;

    while(curr)
    {
        if(curr->data < p->data)
        {
            pred = curr;
            curr = curr->right;
        }
        else
        {
            curr = curr->left;
        }
    }

    return pred;
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

    // Find the predecessor of a node
    Node* node = root->right->left; // Example node to find its predecessor
    Node* pred = inorderPred(root, node);
    if (pred)
        cout << "Predecessor of " << node->data << " is " << pred->data << endl;
    else
        cout << "No predecessor found for " << node->data << endl;

    return 0;
}

