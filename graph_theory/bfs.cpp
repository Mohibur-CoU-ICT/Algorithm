// BFS - Breadth First search
#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<bool>& visited, vector<vector<int>>& adj)
{
    visited[s] = 1;
    queue <int> qu;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        cout << u << ' ';
        for(int v : adj[u]) {
            if(visited[v] == 0) {
                qu.push(v);
                visited[v] = 1;
            }
        }
    }
    cout << endl;
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
    bfs(0, visited, adj);

    return 0;
}

/**
5 5
0 1
0 3
1 4
3 4
4 2
0 1 3 4 2
*/
