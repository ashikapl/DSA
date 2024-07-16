// Find the shortest path in directed weighted graph using DFS in linear TC && SC
#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
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

    void topoSortUsingDFS(int src, unordered_map<int, bool>& visited, stack<int>& st)
    {
        visited[src] = true;

        for(auto nbr : adjList[src])
        {
            if(!visited[nbr.first])
            {
               topoSortUsingDFS(nbr.first, visited, st);
            }
        }

        // While returing stores the last call element into the stack which has no more nbr to visit
        st.push(src);
    }

    void shortestPathUsingDFS(int dest, stack<int>& st, int n)
    {
        vector<int> dist (n, INT_MAX);

        int src = st.top();
        st.pop();
        dist[src] = 0;


        for(auto nbr : adjList[0])
        {
            if(dist[0] + nbr.second < dist[nbr.first])
            {
                dist[nbr.first] = dist[0] + nbr.second;
            } 
        }

        while(!st.empty())
        {
            int topNode = st.top();
            st.pop();

            if(dist[topNode] != INT_MAX)
            {
                for(auto nbr : adjList[topNode])
                {
                    if(dist[topNode] + nbr.second < dist[nbr.first])
                    {
                        dist[nbr.first] = dist[topNode] + nbr.second;
                    } 
                }
            }
        }

        cout << "Printing the shortest dis array:: " << endl;
        for(int i = 0; i < n; i++)
        {
            cout << i << "-> "  << dist[i] << endl;
        }
    }
};

int main()
{
    Graph g;

    g.createEdges(0,1,1,1);
    g.createEdges(0,5,5,1);
    g.createEdges(0,6,2,1);
    g.createEdges(1,2,2,1);
    g.createEdges(2,3,3,1);
    g.createEdges(3,4,1,1);
    g.createEdges(5,4,5,1);
    g.createEdges(6,7,4,1);
    g.createEdges(7,8,9,1);
    g.createEdges(8,4,1,1);

    g.printAdjList();

    stack<int> st;
    unordered_map<int, bool> visited;
    g.topoSortUsingDFS(0, visited, st);

    g.shortestPathUsingDFS(4, st, 9);

    return 0;
}