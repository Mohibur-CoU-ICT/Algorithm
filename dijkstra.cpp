/// Dijkstra shortest path algorithm
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define     pii     pair <int, int>
#define     MAX    100001
#define     MP      make_pair

vector <pii> adj[MAX];
int parent[MAX];
int cost[MAX];

void printCost(int v)
{
    for(int i=0; i<v; i++)
    {
        cout << cost[i] << ' ';
    }
    cout << '\n';
}

void init(int v)
{
    for(int i=0; i<v; i++)
    {
        parent[i] = i;
        cost[i] = INT_MAX;
    }
}

void dijkstra(int nodes, int source)
{
    init(nodes);
    cost[source] = 0;
    priority_queue <pii, vector<pii>, greater<pii>> pq;
    pq.push(MP(0, source));
    while(!pq.empty())
    {
        int u = pq.top().second;
        cout << u << ' ';
        pq.pop();
        for(auto x : adj[u])
        {
            int v = x.first;
            int weight = x.second;
            if(cost[v] > cost[u] + weight)
            {
                cost[v] = cost[u] + weight;
                parent[v] = u;
                pq.push(MP(cost[v], v));
            }
        }
    }
    cout << endl;
}

int main()
{
    int nodes, edges, u, v, w, source;
    cin >> nodes >> edges;
    for(int i=0; i<edges; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(MP(v, w));
        adj[v].push_back(MP(u, w));
    }
    cin >> source;
    dijkstra(nodes, source);
    printCost(nodes);

    return 0;
}

/**
8 16
0 1 5
0 4 9
0 7 8
1 2 12
1 3 15
1 7 4
2 3 3
2 6 11
3 6 9
4 5 4
4 6 20
4 7 5
5 2 1
5 6 13
7 2 7
7 5 6
0
Output:
0 5 14 17 9 13 25 8
........................................
9 14
0 1 4
0 7 8
1 2 8
1 7 11
2 3 7
2 8 2
2 5 4
3 4 9
3 5 14
4 5 10
5 6 2
6 7 1
6 8 6
7 8 7
0
Output:
0 4 12 19 21 11 9 8 14
*/
