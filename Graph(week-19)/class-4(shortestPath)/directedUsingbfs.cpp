// Find the shortest path in directed graph using bfs in linear TC && SC
// if weight or distance is not given then we assume the weight as (1)
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<list>
#include<queue>
#include<vector>
using namespace std;

class Graph{
    public:

    unordered_map<int, list<pair<int,int>>> adjList;

    void createEdges(int u, int v, int w, bool direction)
    {
        // direction -> 0 = undirected graph
        // direction -> 1 = directed graph

        adjList[u].push_back({v,w});
        if(direction == 0)
        {
            // means undirected
            adjList[v].push_back({u,w});
        }
    }

    void printAdjList()
    {
        for(auto node: adjList)
        {
            cout << node.first << "-> ";
            for(auto nbr : node.second)
            {
                cout << "(" << nbr.first << "," << nbr.second << ")";
            }
            cout << endl;
        }
    }

    void shortestPathUsingBFS(int src, int dest)
    {
        queue<int> q;
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;

        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while(!q.empty())
        {
            int fNode = q.front();
            q.pop();

            for(auto nbr : adjList[fNode])
            {
                if(!visited[nbr.first])
                {
                    q.push(nbr.first);
                    visited[nbr.first] = true;
                    parent[nbr.first] = fNode;
                }
            }
        }
        
        vector<int> ans;
        int node = dest;
        while(node != -1)
        {
            ans.push_back(node);
            node = parent[node];
        }

        reverse(ans.begin(), ans.end());

        cout << "Printing the Shortest Path:: " << endl;
        for(auto i : ans)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;

    // int n = 5;
    g.createEdges(0,1,1,1);
    g.createEdges(0,2,1,1);
    g.createEdges(1,3,1,1);
    g.createEdges(2,1,1,1);
    g.createEdges(2,3,1,1);
    g.createEdges(2,4,1,1);
    g.createEdges(4,3,1,1);

    g.printAdjList();

    int src = 0;
    int dest = 3;

    g.shortestPathUsingBFS(src, dest);

    return 0;
}