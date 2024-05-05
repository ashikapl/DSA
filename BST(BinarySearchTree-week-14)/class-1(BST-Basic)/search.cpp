// Search Target Value in BST
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

bool findNode(Node *root, int target)
{
    if (root == NULL) // not found
    {
        return false;
    }

    if (root->data == target) // data found
    {
        return true;
    }

    if (target > root->data)
    {
        // right subtree search
        return findNode(root->right, target);
    }
    else
    {
        // left subtree search
        return findNode(root->left, target);
    }
}

int main()
{
    Node *root = NULL;
    cout << "Enter the Nodes value: " << endl;
    takeInput(root);
    cout << "Printing the BST: " << endl;
    lOT(root);
    cout << endl;

    bool ans = findNode(root, 14);
    if (ans)
    {
        cout << "Node is present! " << ans << endl;
    }
    else
    {
        cout << "Node is not present! " << ans << endl;
    }

    return 0;
}