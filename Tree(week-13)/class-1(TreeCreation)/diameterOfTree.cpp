// Diameter of Tree
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
        left = NULL;
        right = NULL;
    }
};

int height(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftMax = height(root->left);
    int rightMax = height(root->right);
    int ans = max(leftMax, rightMax) + 1;

    return ans;
}

int diameter(Node *root)
{

    if (root == NULL)
    {
        return 0;
    }

    int leftPart = diameter(root->left);
    int rightPart = diameter(root->right);
    int bothPart = height(root->left) + height(root->right) + 1;

    int ans = max(leftPart, max(rightPart, bothPart));

    return ans;
}

int main()
{
    // Creating nodes for the tree
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // Calculating the diameter of the tree
    int d = diameter(root);
    cout << "The diameter of the tree is: " << d << endl;

    return 0;
}
