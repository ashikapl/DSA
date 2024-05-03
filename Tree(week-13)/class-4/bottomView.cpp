// Bottom View of binary tree
#include<iostream>
#include<queue>
#include<map>
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

vector <int> bottomView(Node *root) 
{
        vector<int> ans;
        
        if(root == NULL) return ans;

        map<int,int> mp;
    
        queue<pair<Node*, int> > q;
        q.push(make_pair(root,0));
    
        while(!q.empty())
        {
            pair<Node*,int> temp = q.front();
            q.pop();
    
            Node* frontNode = temp.first;
            int hd = temp.second;
    
            mp[hd] = frontNode->data; 
    
            if(frontNode->left)
            {
                q.push(make_pair(frontNode->left,hd-1));
            }
            if(frontNode->right)
            {
                q.push(make_pair(frontNode->right,hd+1));
            }
        }
        
        for(auto i: mp)
        {
            ans.push_back(i.second);
        }
        
        return ans;
}

int main()
{
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->right= new Node(6);
    root->right->right->right = new Node(7);

    vector<int> ans = bottomView(root);

    for(auto i: ans)
    {
        cout << i << " ";
    }

    return 0;
}