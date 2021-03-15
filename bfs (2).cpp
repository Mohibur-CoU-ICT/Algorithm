// BFS - Breadth First search
#include <bits/stdc++.h>
using namespace std;

void bfs(int s, vector<bool>& visited, vector<vector<int>>& adj)
{
    queue <int> qu;
    qu.push(s);
    visited[s] = 1;
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
    vector <bool> visited(node);
    for(int i=0; i<node; i++){
        if(!visited[i]){
            bfs(0, visited, adj);
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
0 1 3 4 2
*/
