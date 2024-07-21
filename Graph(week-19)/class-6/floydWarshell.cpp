// Floyd Warshall Algorithm -> find the shortest distance from each node to the every other node
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

    void floydWarshall(int n)
    {
        // 2d array of distance 
        vector<vector<int>> dist(n, vector<int>(n, 1e9)); // 1 which follow 9 zeroes (1000,000,000)
        
        // put zeroes on diagonal of distance array
        for(int i = 0; i < n; i++)
        {
            dist[i][i] = 0;
        }

        // graph ke according distance insert kardo
        for(auto i : adjList)
        {
            for(auto nbr : i.second)
            {
                int u = i.first;
                int v = nbr.first;
                int wt = nbr.second;
                dist[u][v] = wt;
            }
        }

        for(int helper = 0; helper < n; helper++)
        {
            for(int src = 0; src < n; src++)
            {
                for(int des = 0; des < n; des++)
                {
                    dist[src][des] = min(dist[src][des], dist[src][helper] + dist[helper][des]);
                }
            }
        }

        cout << "Printing the distance array!" << endl;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << dist[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph g;

    g.createEdges(0,1,3,1);
    g.createEdges(0,3,5,1);
    g.createEdges(1,0,2,1);
    g.createEdges(1,3,4,1);
    g.createEdges(2,1,1,1);
    g.createEdges(3,2,2,1);

    g.printAdjList();
    cout << endl;
    g.floydWarshall(4);

    return 0;
}