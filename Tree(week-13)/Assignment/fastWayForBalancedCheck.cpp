// Fast way to check that the binary tree is Balanced or not
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

bool isBalanced = true;

int height(Node* root)
{
    if(root == NULL) return 0;
        
    int lh = height(root->left);
    int rh = height(root->right);
        
    if(isBalanced && abs(lh - rh) > 1)
    {
        isBalanced = false;;
    }
        
    return max(lh,rh)+1;
}

bool checkBalanced(Node* root)
{
    height(root);
    return isBalanced;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(10);
    root->right = new Node(39);
    root->left->left = new Node(5);
    // root->left->right = new Node(55);
    // root->right->left = new Node(66);
    // root->right->left->right = new Node(77);

    bool ans = checkBalanced(root);

    if(ans == true)
    {
        cout << "Tree is Balanced!" << endl;
    }
    else
    {
        cout << "Tree is not Balanced!" << endl;
    }

    return 0;

}