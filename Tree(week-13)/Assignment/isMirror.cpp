// Tree is Mirror or not
// Mirror means ek hi tree ke dono side same but opposite side mein hone chahiye
#include<iostream>
using namespace std;

class Node
{
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

bool isMirror(Node* a, Node* b)
{
    if(!a && !b) return true;

    if(a && b)
    {
        return (a->data == b->data)
            && isMirror(a->left,b->right)
            && isMirror(a->right,b->left);
    }

    return false;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool ans = isMirror(root->left,root->right);

    if(ans)
    {
        cout << "Tree is Mirror!" << endl;
    }
    else
    {
        cout << "Tree is not Mirror!" << endl;
    }

    return 0;
}

