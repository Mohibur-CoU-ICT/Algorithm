/* Dijkstra algorithm : 
Given a graph and a source vertex in graph, 
find shortest paths from source to all vertices in the given graph. 
*/
#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

void printAdjacencyMatrix(vector<pii> adj[], int n) {
  for (int i=0; i<n; i++) {
    cout << i << " : ";
    for (auto x : adj[i]) {
      cout << x.first << " ";
    }
    cout << endl;
  }
}

void dijkstra(vector<pii> adj[], int source, int node) {
  vector<int> cost(node, INT_MAX), parent(node, -1);
  cost[source] = 0;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push(make_pair(cost[source], source));

  while (!pq.empty()) {
    int u = pq.top().second;
    // cout << u << " ";
    pq.pop();

    for (auto x : adj[u]) {
      int v = x.first;
      int w = x.second;
      if (cost[v] > cost[u] + w) {
        parent[v] = u;
        cost[v] = cost[u] + w;
        pq.push(make_pair(cost[v], v));
      }
    }
  }
  // cout << endl;

  for (int c : cost) {
    cout << c << " ";
  }
  cout << endl;
}

int main() {
  int node, edge, u, v, w, source;
  cin >> node >> edge;
  vector<pii> adj[node];
  for (int i=0; i<edge; i++) {
    cin >> u >> v >> w;
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
  }
  cin >> source;
  // printAdjacencyMatrix(adj, node);
  dijkstra(adj, source, node);

  return 0;
}

/*
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
