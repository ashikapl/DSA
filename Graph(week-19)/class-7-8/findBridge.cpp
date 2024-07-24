// Find the bridge in a graph using (tarjan's algo) in undirected graph
// bridge means the edge which has no other way to go from that node to other node except parent node
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph 
{
    public:
    unordered_map<int, list<int>> adjList;

    void createEdges(int u, int v, bool direction)
    {
        // direction -> 0 means undirected graph
        // direction -> 1 means directed graph
        adjList[u].push_back(v);
        
        if(direction == 0)
        {
            adjList[v].push_back(u);
        }
    }

    void findBridge(int src, int parent, int& timer, vector<int>& tin, vector<int>& low, unordered_map<int, bool>& visited)
    {
        visited[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        for(auto nbr : adjList[src])
        {
            if(nbr == parent)
            {
                continue;
            }
            if(!visited[nbr])
            {
                // dfs calll
                findBridge(nbr, src, timer, tin, low, visited);

                // low update
                low[src] = min(low[src], low[nbr]);

                // check for bridge
                if(low[nbr] > tin[src])
                {
                    cout << nbr << "------" << src << " is a bridge!" << endl;
                }
            }
            else
            {
                // node is visited and not a parent
                // low update
                low[src] = min(low[src], low[nbr]);
            }
        }
    }
};

int main()
{
    Graph g;

    g.createEdges(0,1,0);
    g.createEdges(0,2,0);
    g.createEdges(0,3,0);
    g.createEdges(2,1,0);
    g.createEdges(3,4,0);

    int n = 5;
    int timer = 0;
    vector<int> tin(n);
    vector<int> low(n);
    unordered_map<int, bool> visited;

    g.findBridge(0,-1,timer,tin,low,visited);

    return 0;
}
