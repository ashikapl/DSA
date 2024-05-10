// Build BST using preorder 
#include <iostream>
#include<queue>
#include<vector>
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

Node* buildBST(int &i, int min, int max, vector<int>& preorder)
{
    if(i >= preorder.size()) return NULL;

    Node* root = NULL;
    if(preorder[i] > min && preorder[i] < max)
    {
        root = new Node(preorder[i++]);
        root->left = buildBST(i,min,root->data,preorder);
        root->right = buildBST(i,root->data,max,preorder);
    }
    return root;}

Node* bstFromPreorder(vector<int>& preorder) 
{
    int min = INT_MIN; int max = INT_MAX;
    int i = 0;
    return buildBST(i,min,max,preorder);
}

void lOT(Node *root) // Level Order Traversal (lOT)
{
    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{
    vector<int> preorder = {10, 5, 1, 7, 40, 50};
    Node* root = bstFromPreorder(preorder);
    cout << "Tree: " << endl;
    lOT(root);

    return 0;
} 