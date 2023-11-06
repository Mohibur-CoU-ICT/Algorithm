/*
The Floyd Warshall Algorithm is an all pair shortest path algorithm unlike 
Dijkstra and Bellman Ford which are single source shortest path algorithms. 
This algorithm works for both the directed and undirected weighted graphs. 
But, it does not work for the graphs with negative cycles (where the sum of 
the edges in a cycle is negative). It follows Dynamic Programming approach 
to check every possible path going via every possible node in order to 
calculate shortest distance between every pair of nodes.
*/
#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;

int arr[MAX][MAX];
int cost[MAX][MAX];
int nodes, edges;

void printSolution() {
  cout << "Shortest distance matrix:" << endl;
  for (int i=0; i<nodes; i++) {
    for (int j=0; j<nodes; j++) {
      if (cost[i][j] == INT_MAX) {
        cost[i][j] = -1;
      }
      cout << setw(5) << cost[i][j] << " ";
    }
    cout << endl;
  }
}

void floydWarshall() {
  for (int k=0; k<nodes; k++) {
    for (int i=0; i<nodes; i++) {
      for (int j=0; j<nodes; j++) {
        if (cost[i][k] != INT_MAX && cost[k][j] != INT_MAX && cost[i][k] + cost[k][j] < cost[i][j]) {
          cost[i][j] = cost[i][k] + cost[k][j];
        }
      }
    }
  }
}

int main() {
  int u, v, w;
  cin >> nodes >> edges;
  for (int i=0; i<nodes; i++) {
    for (int j=0; j<nodes; j++) {
      cost[i][j] = (i==j ? 0 : INT_MAX);
    }
  }
  for (int i=0; i<edges; i++) {
    cin >> u >> v >> w;
    arr[u][v] = w;
    cost[u][v] = w;
  }
  floydWarshall();
  printSolution();

  return 0;
}

/*
input:
4 4
0 1 5
0 3 10
1 2 3
2 3 1
output:
0 5 8 9
-1 0 3 4
-1 -1 0 1
-1 -1 -1 0
*/
