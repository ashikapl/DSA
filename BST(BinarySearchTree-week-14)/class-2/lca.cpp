// Lowest Common Ancestor
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
        left = right = NULL;
    }
};

Node *insertAtBST(Node *root, int data)
{
    if (root == NULL)
    {
        // first node->data
        root = new Node(data);
        return root;
    }

    // not first node
    if (root->data > data)
    {
        // insert at left agr root->data se chotta hoto
        root->left = insertAtBST(root->left, data);
    }
    else
    {
        // insert at right agr root->data se baada hoto
        root->right = insertAtBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertAtBST(root, data);
        cin >> data;
    }
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

Node* LCA(Node *root, int n1, int n2)
{
    if(root == NULL) return NULL;
            
    if(n1 < root->data && n2 < root->data)
    {
        return LCA(root->left,n1,n2);
    }
    else if(n1 > root->data && n2 > root->data)
    {
                return LCA(root->right,n1,n2);
    }
            
    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the Nodes value: " << endl;
    takeInput(root);
    cout << "Printing the BST: " << endl;
    lOT(root);
    cout << endl;
    
    int p = 16;
    int q = 18;
    Node* a = LCA(root,p,q);
    cout << "Lowest Common Ancestor is: " << a->data << endl;
    
    return 0;
}
