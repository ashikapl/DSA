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
};

int main() {
    Graph g;

    int n = 5;
    g.createEdges(0, 1, 1);
    g.createEdges(0, 2, 1);
    g.createEdges(2, 3, 1);
    g.createEdges(2, 4, 1);
    g.createEdges(4, 2, 0); // This would create a cycle

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

    return 0;
}