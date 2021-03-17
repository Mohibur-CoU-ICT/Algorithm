// DFS - Depth First search (Recursive)
#include <bits/stdc++.h>
using namespace std;

void dfs(int u, vector<bool>&visited, vector<vector<int>>& adj)
{
    cout << u << ' ';
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
    vector<vector<int>>adj(node, vector<int>());
    for(int i=0; i<edge; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector <bool> visited(node);
    for(int i=0; i<node; i++){
        if(!visited[i]){
            dfs(0, visited, adj);
        }
    }
    cout << endl;

    return 0;
}
/**
5 5
0 1
0 3
1 4
3 4
4 2
0 1 4 2 3
*/
