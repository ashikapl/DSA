// Bellman Ford Algorithm -> in directed or undirected -ve weighted graph 
// TC -> O(N*(V+E)) or O(V*E)
#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<pair<int,int>> > adjList;

    // here we can insert weight also with the help of list<pair<int,int>>
    void createEdges(int u, int v, int w, bool direction)
    {
    // direction -> 0 -- undirected graph
    // direction -> 1 -- directed graph
    // create edge from u to v
    adjList[u].push_back({v,w});
    
    if(direction == 0)
    {
        // undirected graph
        // create edge from v to u
        adjList[v].push_back({u,w});
    }
    }

    void printAdjList()
    {
        cout << "Printing the adjList" << endl;
        for(auto node: adjList)
        {
            cout << node.first << "-> ";
            for(auto neighbour: node.second)
            {
                cout << "(" << neighbour.first << ", " << neighbour.second << ")";
            }
            cout << endl;
        }
    }

    void bellmanFordAlgo(int n, int src)
    {
        // assuming directed -ve weighted graph
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // n-1 relaxation steps
        for(int i = 0; i < n-1; i++)
        {
            for(auto it : adjList)
            {
                for(auto nbr : it.second) // here it.second is weight of src node or curr node
                {
                    int u = it.first;
                    int v = nbr.first;
                    int wt = nbr.second;

                    if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                    {
                        dist[v] = dist[u] + wt;
                    }
                }
            }
        }

        cout << "printing the distance array" << endl;
        for(auto i : dist)
        {
            cout << i << " ";
        }
        cout << endl;

        // to check for -ve cycle is present or not
        bool cycleDect = false;
        for(auto it : adjList)
        {
            for(auto nbr : it.second) // here it.second is weight of src node or curr node
            {
                int u = it.first;
                int v = nbr.first;
                int wt = nbr.second;

                if(dist[u] != INT_MAX && dist[u] + wt < dist[v])
                {
                    cycleDect = true;
                    break;
                }
            }
        }

        if(cycleDect) 
            cout << "-ve Cycle present" << endl;
        else
            cout << "-ve Cycle absent" << endl;
    }
};

int main()
{
    Graph g;

    g.createEdges(0,1,-1,1);
    g.createEdges(0,2,4,1);
    g.createEdges(1,2,3,1);
    g.createEdges(1,3,2,1);
    g.createEdges(1,4,2,1);
    g.createEdges(3,1,1,1);
    g.createEdges(3,2,5,1);
    g.createEdges(4,3,-3,1);

    g.printAdjList();
    cout << endl;
    g.bellmanFordAlgo(5, 0);


    return 0;
}