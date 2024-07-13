// Adjacency List -> list, map, vector, set using directed and undirected graph
// SC -> O(v^2) in worst and O(v+e) in average case, where v is vertex and e is edge of graph
#include<iostream>
#include<unordered_map>
#include<queue>
#include<list>
using namespace std;

class Graph{
    public:
    unordered_map<int, list<int> > adjList;

    // here we can insert weight also with the help of list<pair<int,int>>
    void createEdges(int u, int v, bool direction)
    {
    // direction -> 0 -- undirected graph
    // direction -> 1 -- directed graph
    // create edge from u to v
    adjList[u].push_back(v);
    
    if(direction == 0)
    {
        // undirected graph
        // create edge from v to u
        adjList[v].push_back(u);
    }
    }

    void printAdjList()
    {
        for(auto node: adjList)
        {
            cout << node.first << "-> ";
            for(auto neighbour: node.second)
            {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    // Breadth First Search -> BFS
    void BFS(int firstNode, unordered_map<int, bool>& visited)
    {
        queue<int> pq;
        pq.push(firstNode);
        visited[firstNode] = true;

        while(!pq.empty())
        {
            int front = pq.front();
            pq.pop();
            cout << front << " ";

            for(auto it: adjList[front])
            {
                if(!visited[it])
                {
                    pq.push(it);
                    visited[it] = true;
                }
            }
        }
    }

    // Depth First Search -> DFS
    void DFS(int firstNode, unordered_map<int, bool>& visited2)
    {
        cout << firstNode << " ";
        visited2[firstNode] = true;

        for(auto it : adjList[firstNode])
        {
            if(!visited2[it])
            {
                DFS(it, visited2);
            }
        }
    }
};

int main()
{
    Graph g;

    int n = 5;
    g.createEdges(0,1,0);
    g.createEdges(1,3,0);
    g.createEdges(0,2,0);
    g.createEdges(2,4,0);

    g.printAdjList();

    unordered_map<int,bool> visited;
    cout << "Printing the BFS(Breadth First Search) Traversal:: " << endl;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            g.BFS(i, visited);
        }
    }

    cout << endl;

    unordered_map<int,bool> visited2;
    cout << "Printing the DFS(Depth First Search) Traversal:: " << endl;
    for(int i = 0; i < n; i++)
    {
        if(!visited2[i])
        {
            g.DFS(i, visited2);
        }
    }

    return 0;
}