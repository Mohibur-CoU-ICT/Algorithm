/*
Given a directed graph. Find whether it contains any cycle or not.
*/
#include <bits/stdc++.h>
using namespace std;

bool isCyclicUtil(int u, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack) {
  if (!visited[u]) {
    visited[u] = true;
    recStack[u] = true;
    for (int v : adj[u]) {
      if (!visited[v] && isCyclicUtil(v, adj, visited, recStack)) {
        return true;
      }
      else if (recStack[v]) {
        return true;
      }
    }
  }
  recStack[u] = false;
  return false;
}

bool isCyclic(vector<vector<int>>& adj) {
  int node = adj.size();
  vector<bool>visited(node), recStack(node);

  for (int i=0; i<node; i++) {
    if (!visited[i] && isCyclicUtil(i, adj, visited, recStack)) {
      return true;
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
    // adj[v].push_back(u);
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
