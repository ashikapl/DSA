// Kruskal's Algorithm(Disjoint Set) -> finding the minimum spanning tree
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool myComp(const vector<int>& a, const vector<int>& b) 
{
    return a[2] < b[2];
}
    
int findParent(vector<int>& parent, int node)
{
	if(parent[node] == node)
	{
	    return node;
	}
	    
	return parent[node] = findParent(parent, parent[node]); //path compression
}
	
void unionSet(int u, int v, vector<int>& parent, vector<int>& rank)
{
	u = findParent(parent, u);
	v = findParent(parent, v);
	    
	if(rank[u] < rank[v])
	{
	    parent[u] = v;
	    rank[v]++;
	}
	else
	    {
	    parent[v] = u;
	    rank[u]++;
	}
}
	
//Function to find sum of weights of edges of the Minimum Spanning Tree.
int spanningTree(int V, vector<vector<int>> adj[])
{
    // Kruskal's algo
    vector<int> parent(V);
    vector<int> rank(V, 0);
        
    // make all nodes as individual comp
    for(int u = 0; u < V; u++)
    {
        parent[u] = u; // initialize the nodes parent
    }
        
    // make the edges in linear data structure
    vector<vector<int>> edges;
    for(int u = 0; u < V; u++)
    {
        for(auto nbr : adj[u])
        {
            int v = nbr[0];
            int w = nbr[1];
                
            edges.push_back({u,v,w});
        }
    }
        
    sort(edges.begin(), edges.end(), myComp);
    
    int ans = 0;
    for(auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        u = findParent(parent,u);
        v = findParent(parent,v);
            
        if(u != v)
        {
            // union
            unionSet(u,v,parent,rank);
            ans += w;
        }
    }
        
    return ans;
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