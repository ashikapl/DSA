// Check Binary tree is Balanced or not
#include<iostream>
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
        left = NULL;
        right = NULL;
    }
};

int height(Node* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = 1 + max(leftHeight,rightHeight);
        
        return ans;
    }
    
bool isBalanced(Node *root)
{
        if(root == NULL)
        {
            return true;
        }
        
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int diff = abs(leftHeight - rightHeight);
        
        bool currCheck = (diff <= 1);
        
        bool leftCheck = isBalanced(root->left);
        bool rightCheck = isBalanced(root->right);
        
        if(currCheck && leftCheck && rightCheck)
        {
            return true;
        }
        else
        {
            return false;
        }
}

int main()
{
    // Create a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right = new Node(6);

    // Check if the tree is balanced
    if (isBalanced(root))
    {
        cout << "The binary tree is balanced." << endl;
    }
    else
    {
        cout << "The binary tree is not balanced." << endl;
    }

    // Free memory
    delete root->right->right;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}
