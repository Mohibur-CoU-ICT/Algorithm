// detect if a graph is bipartite or not
#include<bits/stdc++.h>
using namespace std;

int n, edge, u, v;

bool bfs(int src, vector<bool>&vis, vector<int>&color, vector<vector<int>>& graph) {
    queue<int>qu;
    qu.push(src);
    vis[src] = true;
    color[src] = 1;
    while(!qu.empty()) {
        int u = qu.front();
        // cout << u << " ";
        qu.pop();
        for(int v : graph[u]) {
            if(color[v] == -1) {
                qu.push(v);
                vis[v] = true;
                color[v] = 1 - color[u];
            }
            else if(color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>>& graph) {
    vector<bool>vis(n);
    vector<int>color(n, -1);
    for(int i=0; i<n; i++){
        if(!vis[i]){
            if(bfs(i, vis, color, graph) == false) {
                return false;
            }
            // cout << "\n";
        }
    }
    return true;
}

int main()
{
    cin >> n >> edge;
    vector<vector<int>> graph(n, vector<int>());

    for(int i=0; i<edge; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    cout << isBipartite(graph) << "\n";

    return 0;
}

/**
4 5
0 1
0 2
0 3
1 2
2 3
Output:
0

4 4
0 1
0 3
1 2
2 3
Output:
1
*/
