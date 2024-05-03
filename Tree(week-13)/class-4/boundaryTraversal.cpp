// Boundary Traversal 
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

// print left Nodes
void leftBoundary(Node* root)
{
    if(root == NULL)
    { 
        return;
    }
    // if both are null it means it is Leaf node 
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }

    //print root 
    cout << root->data << " ";

    if(root->left) 
    {
        leftBoundary(root->left);
    }
    else
    {
        leftBoundary(root->right);
    }
}

void leafNodes(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    if(root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
    }

    leafNodes(root->left);
    leafNodes(root->right);
}

void rightBoundary(Node* root)
{
    if(root == NULL)
    {
        return;
    }
    // leaf Node is found then return
    if(root->left == NULL && root->right == NULL)
    {
        return;
    }

    if(root->right)
    {
        rightBoundary(root->right);
    }
    else
    {
        rightBoundary(root->left);
    }

    cout << root->data << " ";
}

void boundaryTraversal(Node* root)
{
    if(root == NULL) return;
    
    // print root->data
    cout << root->data << " ";
    
    // print left->data
    leftBoundary(root->left);
    
    // print leaf-Nodes
    leafNodes(root->left);
    leafNodes(root->right);

    // print right->data
    rightBoundary(root->right);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(80);
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    root->right->right= new Node(90);
    root->right->left = new Node(50);
    root->left->right->left = new Node(60);
    root->right->left->right = new Node(70);

    cout << "Boundary Traversal: " << endl;
    boundaryTraversal(root);

    return 0;
}