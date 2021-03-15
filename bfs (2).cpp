// BFS - Breadth First search
#include <bits/stdc++.h>
using namespace std;

void bfs(int s, int n, vector<vector<int>>& adj)
{
    int visited[n];
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    visited[s] = 1;
    queue <int> qu;
    qu.push(s);
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        cout << u << ' ';
        for(int v : adj[u]){
            if(visited[v] == 0){
                qu.push(v);
                visited[v] = 1;
            }
        }
    }
}

int main()
{
    int node, edge, u, v;
    cin >> node >> edge;
    vector<vector<int>> adj(node, vector<int>());
    for(int i=0; i<edge; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    bfs(0, node, adj);

    return 0;
}
/**
5 5
0 1
0 3
1 4
3 4
4 2
*/
