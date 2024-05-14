// Convert the Complete BST into Heap
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
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

void inorder(Node* root, vector<int> &v)
{
    if(root == NULL) return;

    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}

void convertBSTtoHeap(vector<int> v, int n)
{
    priority_queue<int> pq;

    for(int i = 0; i < n; i++)
    {
        pq.push(v[i]);
    }

    while(!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }
}

int main()
{
    Node* root = new Node(50);
    root->left = new Node(40);
    root->right = new Node(90);
    root->left->left = new Node(20);
    root->left->right = new Node(45);
    root->right->left = new Node(70);
    root->right->right = new Node(100);

    vector<int> v;
    inorder(root,v);

    int n = v.size();
    convertBSTtoHeap(v,n);

    return 0;
}
