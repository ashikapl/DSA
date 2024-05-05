// Delete Node from BST
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

int findMax(Node *root)
{
    Node *temp = root;
    if (temp == NULL)
    {
        return -1;
    }

    while (temp->right != NULL)
    {
        temp = temp->right;
    }

    return temp->data;
}

Node* deleteNode(Node* root, int target)
{
    if(root == NULL)
    {
        return NULL;
    }

    if(root->data == target)
    {
        // 4 cases problem
        // case1 -> both are NULL
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        // case2 -> Only Left is NULL
        else if(root->left == NULL && root->right != NULL)
        {
            Node* child = root->right;
            delete root;
            return child;
        }
        // case3 -> Only right is NULL
        else if(root->left != NULL && root->right == NULL)
        {
            Node* child = root->left;
            delete root;
            return child;
        }
        // case4 -> Both are not NULL
        else
        {
           // find Predecessor from left subtree
           int inOrderPre = findMax(root->left); 
           // store in inOrderPre
           root->data = inOrderPre;
           // delete inOrderPre form left subtree
           root->left = deleteNode(root->left,inOrderPre);
           return root;
        }
    }

    if(target > root->data)
    {
        // right subtree search
        root->right = deleteNode(root->right,target);
    }
    else if(target < root->data)
    {
        // left subtree search
        root->left = deleteNode(root->left,target);
    }

    return root;
}

int main()
{
    Node *root = NULL;
    cout << "Enter the Nodes value: " << endl;
    takeInput(root);
    cout << "Printing the BST before deletion: " << endl;
    lOT(root);

    root = deleteNode(root,60);
    cout << "Printing the BST after deletion: " << endl;
    lOT(root);

    return 0;
}