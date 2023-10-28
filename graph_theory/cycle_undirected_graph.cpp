/*
Given an undirected graph. Find whether it contains any cycle or not.
*/
#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
  visited[u] = true;

  for (int v : adj[u]) {
    if (!visited[v]) {
      if(isCyclicUtil(v, u, adj, visited)) {
        return true;
      }
    }
    else if (v != parent) {
      return true;
    }
  }

  return false;
}

bool isCyclic(vector<vector<int>>& adj) {
  int node = adj.size();
  vector<bool>visited(node);
  for (bool b : visited) cout << b << " "; cout << endl;

  for (int i=0; i<node; i++) {
    if (!visited[i]) {
      if (isCyclicUtil(i, -1, adj, visited)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int node, edge, u, v;
  cin >> node >> edge;
  vector<vector<int>> adj(node, vector<int>());

  for (int i=0; i<edge; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  if (isCyclic(adj)) {
    cout << "Graph contains cycle" << endl;
  }
  else {
    cout << "Graph doesn't contain any cycle" << endl;
  }

  return 0;
}

/*
3 3
0 1
1 2
2 0
*/
