#include<iostream>
#include<queue>
#include<map>
#include<set>
#include<vector>
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

vector<vector<int>> verticalTraversal(Node* root)
{
    vector<vector<int>> ans;
    queue<pair<Node*, pair<int,int>>> q; // Node=val, {int,int= row,col}
    q.push({root,{0,0}});
    map<int, map<int,multiset<int>>> mp; // int=indexValue, map->int=row, multiset-int = data

    while(!q.empty())
    {
        auto front = q.front(); q.pop();
        Node*& node = front.first;
        auto& coordinate = front.second;

        int& row = coordinate.first;
        int& col = coordinate.second;

        mp[col][row].insert(node->data);

        if(node->left)
        {
            q.push({node->left,{row+1,col-1}});
        }
        if(node->right)
        {
            q.push({node->right,{row+1,col+1}});
        }
    }

    // Now store the vertical nodes into ansVector
    for(auto it:mp)
    {
        auto& colmp = it.second;
        vector<int> v;
        for(auto colIt:colmp)
        {
            auto& mset = colIt.second;
            v.insert(v.end(),mset.begin(),mset.end());
        }
        ans.push_back(v);
    }
    return ans;
}

int main()
{
    Node* root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(70);

    vector<vector<int>> ans = verticalTraversal(root);

    cout << "Printing the values: " << endl;
    for(auto i: ans)
    {
        for(auto j: i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}
