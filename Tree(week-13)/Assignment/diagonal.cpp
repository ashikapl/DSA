#include<iostream>
#include<queue>
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

void diagonal(Node *root)
{
   if(!root) return;
   
   queue<Node*> q;
   q.push(root);
   
   while(!q.empty())
   {
       Node* temp = q.front(); q.pop();
       while(temp)
       {
           cout << temp->data << " ";
           if(temp->left)
           {
               q.push(temp->left);
           }
           temp = temp->right;
       }
   }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    diagonal(root);

    return 0;
}