// Directed Graph -> Cycle Detection using DFS && BFS
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
#include <queue>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void createEdges(int u, int v, bool direction) {
        adjList[u].push_back(v);
        if (direction == 0) {
            adjList[v].push_back(u);
        }
    }

    void printAdjList() {
        for (auto node : adjList) {
            cout << node.first << " -> ";
            for (auto neighbour : node.second) {
                cout << neighbour << ", ";
            }
            cout << endl;
        }
    }

    bool checkCycleUsingDFS(int src, unordered_map<int, bool>& visited, unordered_map<int, bool>& DFSVisited)
    {
        visited[src] = true;
        DFSVisited[src] = true;

        for(auto nbr : adjList[src])
        {
            if(!visited[nbr])
            {
                bool check = checkCycleUsingDFS(nbr, visited, DFSVisited);
                if(check)
                {
                    return true;
                }
            }
            // visited[nbr] == true
            if(visited[nbr] == true && DFSVisited[nbr] == true)
            {
                return true;
            }
        }

        // yaha pr jb function call stack se return hoga tb DFSVisited mein uski entry wps false ho jayegi (backTrack)
        DFSVisited[src] = false;
        return false;
    }

    // BFS -> by Kahn's algorithm (Topological Sort)(same code) only ans.size() != n then cycle present
    // where n is the size of graph or nodes in the graph
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

int main() {
    Graph g;

    int n = 5;
    g.createEdges(0, 1, 1);
    g.createEdges(0, 2, 1);
    g.createEdges(2, 3, 1);
    g.createEdges(2, 4, 1);
    g.createEdges(4, 2, 0);// This would create a cycle

    g.printAdjList();
    cout << endl;

    // BFS
    bool ans = false;
    unordered_map<int, bool> visited;
    unordered_map<int, bool> DFSVisited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans = g.checkCycleUsingDFS(i, visited, DFSVisited);
            if (ans) {
                break;
            }
        }
    }

    if (ans) {
        cout << "Cycle is Present in directed Graph!" << endl;
    } else {
        cout << "Cycle is Absent!" << endl;
    }

    vector<int> result;
    g.topoSortUsingBFS(n, result);
    // here is no. of nodes in the graph or size of the graph
    // if ans.size() == n then is topo sort but not a cycle
    // and if ans.size() != n then, it is invalid topo sort and cycle is present
    // BFS is solved by kahn's algorithm by(Topological Sort)

    if(result.size() == n)
    {
        cout << "Its a valid Topo Sort there is no cycle present!" << endl;
    }
    else
    {
        cout << "Cycle present it is an invalid Topo Sort" << endl;
    }

    return 0;
}