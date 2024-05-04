// Check two trees are identical or not
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

bool isIdenticalTree(Node* a, Node* b)
{
    if(!a && !b) return true;

    if(a && b)
    {
        return (a->data == b->data)
            && isIdenticalTree(a->left,b->left)
            && isIdenticalTree(a->right,b->right);
    }

    return false;
}

int main()
{
    Node* root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);

    Node* root2 = new Node(1);
    root2->left = new Node(2);
    // root2->right = new Node(3);

    bool ans = isIdenticalTree(root1,root2);

    if(ans)
    {
        cout << "Tree is Identical!" << endl;
    }
    else
    {
        cout << "Tree is not Identical!" << endl;
    }

    return 0;
}