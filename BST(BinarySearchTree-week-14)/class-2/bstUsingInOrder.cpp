// Create BST using inOrder Traversal
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

Node* BSTusingInorder(int inOrder[], int s, int e)
{
    // Base case
    if(s > e)
    {
        return NULL;
    }

    int mid = (s+e)/2;
    int element = inOrder[mid];
    Node* root = new Node(element);

    root->left = BSTusingInorder(inOrder,s,mid-1);
    root->right = BSTusingInorder(inOrder,mid+1,e);

    return root;
}

int main()
{
    int inOrder[] = {4,8,10,12,14,16,18};
    int s = 0;
    int e = 6;

    Node* root = BSTusingInorder(inOrder,s,e);
    lOT(root);

    return 0;
}