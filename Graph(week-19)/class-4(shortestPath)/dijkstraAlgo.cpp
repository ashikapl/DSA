// Dijkstra Alogrithm -> To find the shortest path from the src node to every other node in the graph
// In undirected weighted graph in linear time complexity
#include<iostream>
#include<unordered_map>
#include<set>
#include<list>
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

    void dijkstraAlgo(int src, int n)
    {
        vector<int> dist(n, INT_MAX);
        set<pair<int, int>> st;

        // src node 
        dist[src] = 0;
        st.insert(make_pair(0, src));

        while(!st.empty())
        {
            // fetch the pair from set and (*) is for actual value
            auto topElement = *(st.begin());
            int nodeDist = topElement.first;
            int node = topElement.second;

            // pop from set
            st.erase(st.begin());
           
            // neighbours
            for(auto nbr : adjList[node])
            {
                // here nodeDist -> topElement->distance
                // nbr.second -> nbr->distance (1,2) where 1 is node and 2 is distance
                // dist[nbr.first] -> dist array ke adndr nbr ka jobhi index hai uski value hai [first] (INT_MAx rakha hai)
                // and nbr(digit) giving in graph as in the form of node and in dist array we consider as index no as node no.
                if(nodeDist + nbr.second < dist[nbr.first])
                {
                    // update the distance
                    // find the entry of the curr node nbr
                    auto res = st.find(make_pair(dist[nbr.first], nbr.first));

                    if(res != st.end())
                    {
                        st.erase(res);
                    }

                    //  update the dist values in dist array and set
                    dist[nbr.first] = nodeDist + nbr.second;
                    st.insert(make_pair(dist[nbr.first], nbr.first));
                }
            }
        }

        cout << "Printing the distance array from the src to every other node:::-->> " << endl;
        for(auto i : dist)
        {
            cout << i << " ";
        }
    }
};

int main()
{
    Graph g;

    int n = 8;
    g.createEdges(1,2,2,0);
    g.createEdges(1,4,6,0);
    g.createEdges(1,5,11,0);
    g.createEdges(2,3,7,0);
    g.createEdges(3,6,4,0);
    g.createEdges(4,6,8,0);
    g.createEdges(5,7,3,0);
    g.createEdges(6,7,1,0);
    // g.createEdges(5,4,6,0);

    g.dijkstraAlgo(1, n);

    return 0;
}