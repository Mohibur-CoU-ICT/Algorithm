// DFS - Depth First search
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

int main()
{
    int node, edge, u, v;
    cin >> node >> edge;
    vector<bool> visited(node);
    vector<vector<int>> adj(node, vector<int>());
    for(int i=0; i<edge; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, visited, adj);

    return 0;
}

/**
5 5
0 1
0 3
1 4
3 4
4 2
0 3 4 2 1
*/
