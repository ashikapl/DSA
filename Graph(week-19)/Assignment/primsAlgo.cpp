// Prim's Algorithm -> find the minimum spanning tree(mst)

#include<iostream>
#include<vector>
using namespace std;

int getMinValueNode(vector<int>& key, vector<int>& mst)
{
	int temp = INT_MAX;
	int index = -1;
	    
	for(int i = 0; i < key.size(); i++)
	{
	     if(mst[i] == false && key[i] < temp)
	    {
	        temp = key[i];
	        index = i;
	    }
	}
	    
	return index;
}
	
//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // prim's algo
    vector<int> key(V, INT_MAX);
    vector<int> mst(V, false); // minimum spanning tree the node is traversed or not
    vector<int> parent(V, -1); // final mst
        
    key[0] = 0;
        
    while(true)
    {
        // step1
        int u = getMinValueNode(key,mst);
            
        if(u == -1) break;
            
        // step2
        mst[u] = true;
            
        // step3
        for(auto nbr : adj[u])
        {
            int v = nbr[0];
            int w = nbr[1];
                
            if(mst[v] == false && w < key[v])
            {
                key[v] = w;
                parent[v] = u;
            }
        }
    }
        
    // sum of weights of final tree edges
    int sum = 0;
    for(int u = 0; u < parent.size(); u++)
    {
        if(parent[u] == -1) continue;
            
        for(auto nbr : adj[u])
        {
            int v = nbr[0];
            int w = nbr[1];
                
            if(v == parent[u])
            {
                sum += w;
            }
        }
    }
        
    return sum;
}

int main()
{
    int V = 5; // Number of vertices in the graph
    vector<vector<int>> adj[V];
    
    // Adding edges to the graph
    adj[0].push_back({1, 2});
    adj[0].push_back({3, 6});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 8});
    adj[1].push_back({4, 5});
    adj[2].push_back({1, 3});
    adj[2].push_back({4, 7});
    adj[3].push_back({0, 6});
    adj[3].push_back({1, 8});
    adj[4].push_back({1, 5});
    adj[4].push_back({2, 7});
    
    int result = spanningTree(V, adj);
    cout << endl;
    cout << "The sum of the weights of the Minimum Spanning Tree is: " << result << endl;
    cout << endl;


    return 0;
}