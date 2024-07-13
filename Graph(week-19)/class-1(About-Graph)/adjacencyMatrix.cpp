// Adjcency Matrix -2-D array using directed or undirected graph
// SC -> O(v^2) in worst and average case both, where v is vertex of graph
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter the no. of nodes: ";
    cin >> n;

    cout << endl;

    int e;
    cout << "Enter the no. of edges: ";
    cin >> e;

    cout << endl;

    vector<vector<int>> adj(n, vector<int>(n, 0));

    for(int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;

        // mark the [u][v] index = 1 if it is connect with u->v
        adj[u][v] = 1;
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}