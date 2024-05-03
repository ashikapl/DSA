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

void leftView(Node *root)
{
    if (root == nullptr)
        return;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        bool isFirstNode = true;

        for (int i = 0; i < size; ++i)
        {
            Node *temp = q.front();
            q.pop();

            if (isFirstNode)
            {
                cout << temp->data << endl;
                isFirstNode = false;
            }

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

// Left View with recursion
void lV(Node* root, vector<int> &ans, int level)
{
    if(root == NULL) return;

    if(level == ans.size())
    {
        ans.push_back(root->data);
    }
    
    // left call
    lV(root->left,ans,level+1);
    // right call
    lV(root->right,ans,level+1);
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->right= new Node(60);
    root->right->right->left = new Node(70);

    vector<int> ans;
    int level = 0;

    lV(root,ans,level);

    cout << "Printing leftView: " << endl;
    for(auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}