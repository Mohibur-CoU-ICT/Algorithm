// Prim's Algorithm
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

#define    FIO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define    MP    make_pair
#define    MX    100005
#define    ff    first
#define    ss    second

vector <pii> adj[MX];

int prims(int n, int source)
{
    int ans = 0;
    vector<bool>visited(n);
    vector<int>parent(n, -1);
    vector<int>cost(n, INT_MAX);
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push({0, source});
    cost[source] = 0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        visited[u] = 1;
        for(auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if(!visited[v] && cost[v]>weight)
            {
                cost[v] = weight;
                pq.push({cost[v], v});
                parent[v] = u;
            }
        }
    }
    for(int i=0; i<n; i++){
        if(cost[i]!=INT_MAX){
            ans += cost[i];
        }
        cout<<parent[i]<<" -> "<<i<<endl;
    }
    return ans;
}

int main()
{
    FIO;
//    freopen("Kruskal.txt", "r", stdin);
    int vertex, edges;
    cin >> vertex >> edges;

    for(int i=0; i<edges; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    cout << "MST Cost " << prims(vertex, 0) << endl;

    return 0;
}
/**
8 9
0 3 3
0 4 6
1 5 5
1 6 1
2 4 6
3 5 8
5 6 3
5 7 2
6 7 6
Output: 29

5 7
0 1 7
0 2 4
0 3 1
1 3 8
2 3 3
1 4 6
3 4 6
Output: 16

6 9
0 1 6
0 4 5
1 4 7
1 2 1
4 3 14
2 4 8
2 5 2
2 3 5
3 5 3
Output: 17
*/
