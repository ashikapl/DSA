// Topological Sort -> where the nodes u coming before v where u is independent 
// The only codition in Topological sort is -> (Only use this algo on) -> Directed Acyclic Graph with linear TC
#include<iostream>
#include<unordered_map>
#include<queue>
#include<stack>
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

    void topoSortUsingDFS(int src, unordered_map<int, bool>& visited, stack<int>& st)
    {
        visited[src] = true;

        for(auto nbr : adjList[src])
        {
            if(!visited[nbr])
            {
               topoSortUsingDFS(nbr, visited, st);
            }
        }

        // While returing stores the last call element into the stack which has no more nbr to visit
        st.push(src);
    }

    void topoSortUsingBFS(int n, vector<int>& ans)
    {
        queue<int> q;
        unordered_map<int, int> indegree;

        // calculate the indegree
        for(auto i : adjList)
        {
            int src = i.first;
            for(auto nbr : i.second)
            {
                indegree[nbr]++;
            }
        }

        // put all the nodes into the queue whose indegree is 0
        for(int i = 0; i < n; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
            }
        }

        // bfs logic
        while(!q.empty())
        {
            int fNode = q.front();
            q.pop();

            ans.push_back(fNode);
            // here we can do count also in cycle detection problem of bfs

            for(auto nbr : adjList[fNode])
            {
                indegree[nbr]--;
                if(indegree[nbr] == 0)
                {
                    q.push(nbr);
                }
            }
        }
    }
};

int main()
{
    Graph g;

    int n = 7;
    g.createEdges(0,1,1);
    g.createEdges(0,2,1);
    g.createEdges(1,4,1);
    g.createEdges(2,3,1);
    g.createEdges(4,5,1);
    g.createEdges(4,6,1);

    unordered_map<int, bool> visited;
    stack<int> st;
    for(int i = 0; i < n; i++)
    {
        if(!visited[i])
        {
            g.topoSortUsingDFS(i, visited, st);
        }
    }

    cout << "Topological Sort using BFS:: " << endl;
    while(!st.empty())
    {
        int topNode = st.top();
        st.pop();

        cout << topNode << " ";
    }
    cout << endl;


    vector<int> ans;
    g.topoSortUsingBFS(n, ans);

    cout << "Topological Sort using BFS:: " << endl;
    for(auto i : ans)
    {
        cout << i << " ";
    }

    return 0;
}