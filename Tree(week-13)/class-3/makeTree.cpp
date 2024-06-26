// Make Tree with the help of InOrder and PreOrder Traversal
// and
// Make Tree with the help of InOrder and PostOrder Traversal
#include<iostream>
#include<queue> 
// #include<unordered_map>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// we can use here mapping also to find position
// int find(unordered_map<int,int>& m, int inOrder[], int size)
// {
//     for(int i = 0; i < size; i++)
//     {
//         m[inOrder[i]] = i;
//     }
// }

int findPosition(int arr[], int size, int element, int start)
{
    for(int i = start; i < size; i++)
    {
        if(arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}


// ek hi node ko ek hi baar utilize karna hai isliye preIndex of Call by Reference liya hai
Node* buildTreeWithInPreOrder(int inOrder[],int preOrder[], int size, int &preIndex, int inOrderStart, int inOrderEnd)
{
    // base case
    if(preIndex >= size || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // Step 1:
    int ele = preOrder[preIndex++];
    Node* root = new Node(ele);
    int pos = findPosition(inOrder,size,ele,inOrderStart);

    root->left = buildTreeWithInPreOrder(inOrder,preOrder,size,preIndex,inOrderStart,pos-1);
    root->right = buildTreeWithInPreOrder(inOrder,preOrder,size,preIndex,pos+1,inOrderEnd);

    return root;
}

Node* buildTreeWithInPostOrder(int inOrder[], int postOrder[], int size, int &postIndex, int inOrderStart, int inOrderEnd)
{
    // base case
    if(postIndex < 0 || inOrderStart > inOrderEnd)
    {
        return NULL;
    }

    // A
    int element = postOrder[postIndex];
    postIndex--;
    Node* root = new Node(element);
    int pos = findPosition(inOrder,size,element,inOrderStart);
    // int pos = m[element];

    // root->right
    root->right =  buildTreeWithInPostOrder(inOrder, postOrder, size, postIndex, pos+1, inOrderEnd);

    // root -> left
    root->left =  buildTreeWithInPostOrder(inOrder, postOrder, size, postIndex, inOrderStart, pos-1);

    return root;
}

void levelOrderTraversal(Node *root) // Level Order Traversal (lOT)
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
    // inOrder and preOrder Traversal

    // int inOrder[] = {3,2,4,1,6,5,7};
    // int preOrder[] = {1,2,3,4,5,6,7};
    // int size = 7;
    // int preIndex = 0;
    // int inOrderStart = 0;
    // int inOrderEnd = size - 1;
    
    // Node* root = buildTreeWithInPreOrder(inOrder,preOrder,size,preIndex,inOrderStart,inOrderEnd);

    // Inorder and PostOrder Traversal
    int inOrder[] = {40,20,10,50,30,60};
    int postOrder[] = {40,20,50,60,30,10};
    int size = 6;
    int postIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;

    // unordered_map<int,int> m;
    // Node* root = buildTreeWithInPostOrder(inOrder, postOrder, size, postIndex, inOrderStart, inOrderEnd,m) map is pass by reference

    Node* root = buildTreeWithInPostOrder(inOrder, postOrder, size, postIndex, inOrderStart, inOrderEnd);

    cout << "Build Tree:"<<endl;
    levelOrderTraversal(root);

    return 0;
}