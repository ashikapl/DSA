// Morris Traversal -> Its a InOrder Traversal with (S.C->O(1)) with the help of while loop
// Inorder Traversal is Morris Traversal with S.C->O(1) complexity
#include<iostream>
#include<vector>
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

vector<int> morrisTraversal(Node*root)
{
    vector<int> ans;
    if(root == NULL) return ans;

    Node*curr = root;

    while(curr)
    {
        // left is NULL then , visit it and go right
        if(curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        // left is not NULL
        else
        {
            // find Inorder Predecessor
            Node* pred = curr->left;
            while(pred->right != curr && pred->right)
            {
                pred = pred->right;
            }
            // pred->right is NULL
            if(pred->right == NULL)
            {
                pred->right = curr;
                curr = curr->left;
            }
            else
            {
                // if already visited on left then
                pred->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->left->right->left = new Node(8);

    vector<int> ans = morrisTraversal(root);

    cout << "Morris Traversal:-> ";
    for(auto i:ans)
    {
        cout << i << " ";
    }

    return 0;
}