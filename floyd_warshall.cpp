/// Dijkstra shortest path algorithm
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define     pii     pair <int, int>
#define     MAX     101
#define     MP      make_pair

int arr[MAX][MAX];
int cost[MAX][MAX];
int n, e;

void printSolution()
{
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(cost[i][j] == INT_MAX)
                cost[i][j] = -1;
            cout << cost[i][j] << ' ';
        }
        cout << '\n';
    }
}

void floydWarshall()
{
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(cost[i][k] != INT_MAX && cost[k][j] != INT_MAX
                   && cost[i][k]+cost[k][j] < cost[i][j]){
                    cost[i][j] = cost[i][k] + cost[k][j];
                }
            }
        }
    }
}

int main()
{
    cin >> n >> e;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j) cost[i][j] = 0;
            else cost[i][j] = INT_MAX;
        }
    }
    int u, v, w;
    for(int i=0; i<e; i++)
    {
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
