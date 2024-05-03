// Fast way to find diameter
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

int D = 0;

int height(Node* root)
{
    if(root == NULL) return 0;

    int lh = height(root->left);
    int rh = height(root->right);

    int currD = lh + rh;

    D = max(D,currD);

    return max(lh,rh) + 1;
}

int diameter(Node* root)
{
    height(root);
    return D+1;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);

    int h = diameter(root);

    cout << "Diameter of Binary Tree is: " << h << endl;

    return 0;
}