// Find transitive closure of a graph
/*
Given a directed graph, find out if a vertex v is reachable from another vertex u for 
all vertex pairs (u, v) in the given graph. Here reachable means that there is a path 
from vertex u to v. The reach-ability matrix is called transitive closure of a graph.
*/
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>& visited, vector<vector<int>>& adj)
{
    cout << u << " ";
    visited[u] = 1;
    for(int v : adj[u]) {
        if(visited[v] == 0) {
            dfs(v, visited, adj);
        }
    }
}

void findTransitiveClosure(int node, vector<vector<int>>& adj) {
    vector<vector<bool>> visited(node, vector<bool>(node));

    for (int i=0; i<node; i++) {
        dfs(i, visited[i], adj);
        cout << endl;
    }

    // print the transitive closure
    cout << "Transitive closure of the given graph is:" << endl;
    for (int i=0; i<node; i++) {
        for (int j=0; j<node; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int node, edge, u, v;
    cin >> node >> edge;
    vector<vector<int>> adj(node, vector<int>());
    for(int i=0; i<edge; i++) {
        cin >> u >> v;
        // this is a directed graph
        adj[u].push_back(v);
    }

    findTransitiveClosure(node, adj);

    return 0;
}

/**
5 5
0 1
0 3
1 4
3 4
4 2
Transitive closure of the given graph is:
1 1 1 1 1
0 1 1 0 1
0 0 1 0 0
0 0 1 1 1
0 0 1 0 1
Time Complexity : O(V^2) where V is the number of vertices.
Space complexity : O(V^2) where V is number of vertices.
*/
