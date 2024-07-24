// Strongly Connected Components (SCC) -> using dfs of toposort
// step1 -> dfs of toposort to(find the ordering)
// step2 -> reverse all the edges
// step3 -> count the components at end 
#include <iostream>
#include <unordered_map>
#include <stack>
#include <list>
using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;

    void createEdges(int u, int v, bool direction) {
        // direction -> 0 -- undirected graph
        // direction -> 1 -- directed graph
        // create edge from u to v
        adjList[u].push_back(v);
    
        if (direction == 0) {
            // undirected graph
            // create edge from v to u
            adjList[v].push_back(u);
        }
    }

    void dfs1(int src, stack<int>& s, unordered_map<int, bool>& visited) {
        visited[src] = true;

        for (auto nbr : adjList[src]) {
            if (!visited[nbr]) {
                dfs1(nbr, s, visited);
            }
        }

        s.push(src);
    }

    void dfs2(int src, unordered_map<int, list<int>>& adjNew, unordered_map<int, bool>& visited) {
        visited[src] = true;
        cout << src << " ";

        for (auto nbr : adjNew[src]) {
            if (!visited[nbr]) {
                dfs2(nbr, adjNew, visited);
            }
        }
    }

    int countSCC(int n) {
        stack<int> s;
        unordered_map<int, bool> visited;

        // Step 1: Perform DFS to get the finishing times of vertices
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs1(i, s, visited);
            }
        }

        // Step 2: Reverse the graph
        unordered_map<int, list<int>> adjNew;
        for (auto t : adjList) {
            for (auto nbr : t.second) {
                int u = t.first;
                int v = nbr;
                // insert v -> u
                adjNew[v].push_back(u);
            }
        }

        // Step 3: Perform DFS on the reversed graph in the order defined by the stack
        int count = 0;
        unordered_map<int, bool> visited2;

        while (!s.empty()) {
            int node = s.top();
            s.pop();

            if (!visited2[node]) {
                cout << "Printing " << count + 1 << "th SCC: ";
                dfs2(node, adjNew, visited2);
                cout << endl;
                count++;
            }
        }

        return count;
    }
};

int main() {
    Graph g;

    g.createEdges(0, 1, 1);
    g.createEdges(1, 2, 1);
    g.createEdges(2, 3, 1);
    g.createEdges(2, 4, 1);
    g.createEdges(3, 0, 1);
    g.createEdges(4, 5, 1);
    g.createEdges(5, 6, 1);
    g.createEdges(6, 4, 1);
    g.createEdges(6, 7, 1);

    int ans = g.countSCC(8);
    cout << "Total Strongly Connected Components: " << ans << endl;

    return 0;
}
