//  Create Tree with Node
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

Node *buildTree()
{
    int data;
    cout << "Enter the data: ";
    cin >> data;

    // Base case
    if (data == -1)
    {
        return NULL;
    }

    // Step A -> create Root
    Node *root = new Node(data);

    // Step B -> left recursive call
    cout << "Enter the data to put in left of " << data << endl;
    root->left = buildTree();

    // Step C -> right recursive call
    cout << "Enter the data to put in right of " << data << endl;
    root->right = buildTree();

    return root;
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

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left);

    cout << root->data << " ";

    inorderTraversal(root->right);
}

void preorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->data << " ";

    preorderTraversal(root->left);

    preorderTraversal(root->right);
}

void postorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // LRN

    postorderTraversal(root->left);

    postorderTraversal(root->right);

    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    root = buildTree();

    lOT(root);

    inorderTraversal(root);
    cout << endl;

    preorderTraversal(root);
    cout << endl;

    postorderTraversal(root);

    return 0;
}