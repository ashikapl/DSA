// Largest BST Size 
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

class NodeData
{
    public:
    int size;
    int maxVal;
    int minVal;
    bool validBST;

    NodeData(){};

    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        maxVal = max;
        minVal = min;
        validBST = valid;
    }

};

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

NodeData* largestBST(Node* root, int &ans)
{
    if(root == NULL)
    {
        NodeData* temp = new NodeData(0,INT_MIN,INT_MAX,true);
        return temp;
    }

    NodeData* leftAns = largestBST(root->left, ans);
    NodeData* rightAns = largestBST(root->right, ans);

    //check for BST
    NodeData* currNodeAns= new NodeData();
    
    currNodeAns->size = leftAns->size + rightAns->size + 1;
    currNodeAns->maxVal = max(root->data, rightAns->maxVal);
    currNodeAns->minVal = max(root->data, leftAns->minVal);
    
    if(leftAns->validBST && rightAns->validBST && (root->data > leftAns->maxVal && root->data < rightAns->minVal))
    {
        currNodeAns->validBST = true;
    }
    else
    {
        currNodeAns->validBST = false;
    }

    if(currNodeAns->validBST)
    {
        ans = max(ans,currNodeAns->size);
    }

    return currNodeAns;
}

int main()
{
    Node* root = new Node(20);
    root->left = new Node(15);
    root->right = new Node(40);
    root->left->left = new Node(10);
    root->left->right = new Node(18);
    root->right->left = new Node(30);
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);

    int ans = 0;
    NodeData* result = largestBST(root,ans);
    cout << "Printing the Tree:" << endl;
    lOT(root);
    cout << "The size of largest BST is:-> " << ans << endl;

    return 0;
}

