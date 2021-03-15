// DFS - Depth First search
#include <bits/stdc++.h>
using namespace std;

void dfs(int s, int node, vector<vector<int>>& adj)
{
    int visited[node];
    for(int i=0; i<node; i++){
        visited[i] = 0;
    }
    stack <int> stk;
    stk.push(s);
    while(!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        cout << u << ' ';
        for(int v : adj[u]) {
            if(visited[v] == 0) {
                stk.push(v);
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
    vector<vector<int>>adj(node, vector<int>());
    for(int i=0; i<edge; i++){
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(0, node, adj);

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
