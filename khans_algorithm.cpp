/**
Khan's Algorithm:
    * Directed Acyclic Graph
    * Find topological sort of the graph
    * Topological sorting for Directed Acyclic Graph (DAG) is a
      linear ordering of vertices such that for every directed edge uv,
      vertex u comes before v in the ordering.
    * Topological Sorting for a graph is not possible if the graph is not a DAG.
    * A DAG G has at least one vertex with in-degree 0 and one vertex with out-degree 0.
*/
#include <bits/stdc++.h>
using namespace std;
#define    FIO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define    MX    100005

vector <int> adj[MX];

/// prints topological sort of the given graph
void topologicalSort(int n, int source)
{
    vector<int>indegree(n);
    for(int i=0; i<n; i++){
        for(int j : adj[i]){
            indegree[j]++;
        }
    }
    queue<int>qu;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            qu.push(i);
        }
    }
    int cnt = 0;
    vector<int>top_order;
    while(!qu.empty())
    {
        int u = qu.front();
        qu.pop();
        top_order.push_back(u);
        for(int v : adj[u]){
            if(--indegree[v]==0){
                qu.push(v);
            }
        }
        cnt++;
    }
    if(cnt != n){
        cout << "Topological sorting is not possible. There is a cycle in the graph." << endl;
    }
    else{
        cout << "Topological sorting is : ";
        for(int i : top_order){
            cout << i << ' ';
        }
        cout << endl;
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
    }
    topologicalSort(vertex, 0);

    return 0;
}
/**
6 6
5 2
5 0
4 0
4 1
2 3
3 1
Output:
Topological sorting is : 4 5 2 0 3 1
...................................................
5 5
1 0
0 2
2 1
0 3
3 4
Output:
Topological sorting is not possible. There is a cycle in the graph.
...................................................
5 6
0 3
0 2
1 3
2 3
3 4
0 4
Output:
Topological sorting is : 0 1 2 3 4
*/
