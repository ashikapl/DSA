// Right View of Binary tree
#include <iostream>
#include <queue>
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

void rightView(Node* root, vector<int> &ans, int level)
{
    if(root == NULL) return;

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }

    // right call
    rightView(root->right,ans,level+1);
    // left call
    rightView(root->left,ans,level+1);
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

    vector<int> ans;
    int level = 0;

    rightView(root,ans,level);

    cout << "Printing rightView: " << endl;
    for(auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}