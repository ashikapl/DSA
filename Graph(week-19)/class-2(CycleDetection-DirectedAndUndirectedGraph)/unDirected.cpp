// Undirected Graph -> Cycle Detection Using BFS(Breadth First Search) && DFS(Depth First Search)
// TC -> O(V+E) && SC -> O(V+E)
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

    bool checkCycleUsingBFS(int src, unordered_map<int, bool>& visited) {
        queue<int> q;
        unordered_map<int, int> parent;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;

        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            for (auto nbr : adjList[frontNode]) {
                if (!visited[nbr]) {
                    q.push(nbr);
                    visited[nbr] = true;
                    parent[nbr] = frontNode;
                } else if (nbr != parent[frontNode]) {
                    // Cycle detected
                    return true;
                }
            }
        }

        return false;
    }

    bool checkCycleUsingDFS(int src, unordered_map<int, bool>& visited, int parent)
    {
        visited[src] = true;

        for(auto nbr : adjList[src])
        {
            if(!visited[nbr])
            {
                bool check = checkCycleUsingDFS(nbr, visited, src);
                if(check == true)
                {
                    return true;
                }
            }
            else if(nbr != parent)
            {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Graph g;

    int n = 5;
    g.createEdges(0, 1, 0);
    g.createEdges(0, 2, 0);
    g.createEdges(2, 3, 0);
    g.createEdges(2, 4, 0);
    g.createEdges(4, 2, 0); // This would create a cycle

    g.printAdjList();
    cout << endl;

    // BFS
    bool ans = false;
    unordered_map<int, bool> visited;

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            ans = g.checkCycleUsingBFS(i, visited);
            if (ans) {
                break;
            }
        }
    }

    if (ans) {
        cout << "Cycle is Present in Undirected Graph!" << endl;
    } else {
        cout << "Cycle is Absent!" << endl;
    }

    // DFS
    bool DFSans = false;
    unordered_map<int, bool> visited2;

    for (int i = 0; i < n; i++) {
        if (!visited2[i]) {
            DFSans = g.checkCycleUsingDFS(i, visited2, -1);
            if (DFSans) {
                break;
            }
        }
    }

    if (DFSans) {
        cout << "Cycle is Present in Undirected Graph!" << endl;
    } else {
        cout << "Cycle is Absent!" << endl;
    }

    return 0;
}
