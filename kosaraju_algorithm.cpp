/**
Kosaraju Algorithm:
    Directed graph
    Find strongly connected component
*/
#include <bits/stdc++.h>
using namespace std;
#define    FIO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define    MX    100005

vector <int> adj[MX], radj[MX];

void dfs1(int u, vector<bool>&visited, stack<int>&stk)
{
    visited[u] = 1;
    for(int v : adj[u]){
        if(!visited[v]){
            dfs1(v, visited, stk);
        }
    }
    stk.push(u);
}

void dfs2(int u, vector<bool>&visited)
{
    cout << u << ' ';
    visited[u] = 1;
    for(int v : radj[u]){
        if(!visited[v]){
            dfs2(v, visited);
        }
    }
}

/// prints all strongly connected component
void kosaraju(int n, int source)
{
    int ans = 0;
    vector<bool>visited(n);
    stack<int>stk;
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs1(i, visited, stk);
        }
    }
    for(int i=0; i<n; i++){
        visited[i] = 0;
    }
    while(!stk.empty())
    {
        int u = stk.top();
        stk.pop();
        if(!visited[u]){
            dfs2(u, visited);
            cout<<endl;
        }
    }
}

int main()
{
    FIO;
    int vertex, edges, u, v;
    cin >> vertex >> edges;
    for(int i=0; i<edges; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    kosaraju(vertex, 0);

    return 0;
}
/**
5 5
1 0
0 2
2 1
0 3
3 4
Output:
0 1 2
3
4
...................................................
5 6
0 3
0 2
1 3
2 3
3 4
4 0
Output:
1
0 4 3 2
*/
