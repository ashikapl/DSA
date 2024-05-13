// Check the Binary Tree is Max heap or not
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

pair<bool,int> checkHeap(Node* root)
{
    if(root == NULL)
    {
        pair<bool,int> p = make_pair(true,INT_MIN);
        return p;
    }
    if(root->left == NULL && root->right == NULL)
    {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = checkHeap(root->left);
    pair<bool,int> rightAns = checkHeap(root->right);

    if(leftAns.second < root->data && rightAns.second < root->data && leftAns.first == true && rightAns.first == true)
    {
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }
    else
    {
        pair<bool,int> p = make_pair(false,INT_MIN);
        return p;
    }
}

int main()
{
    Node* root = new Node(20);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(8);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    
    pair<bool,int> ans = checkHeap(root);

    cout << "Binary Tree is Heap or not:-> " << ans.first << endl;

    return 0;

}