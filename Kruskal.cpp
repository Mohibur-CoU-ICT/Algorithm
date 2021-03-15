// Kruskal Algorithm
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, pair<int,int>> piii;

#define    FIO   ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define    MP    make_pair
#define    MX    100005
#define    ff    first
#define    ss    second

int parent[MX];
int rankParent[MX];

vector <piii> edge;

void initializeSet(int n)
{
    for(int i=0; i<n; i++){
        parent[i] = i;
        rankParent[i] = 0;
    }
}

int findParent(int x)
{
    if(x == parent[x])
        return x;
    else
        return parent[x] = findParent(parent[x]);
}

void unionSet(int x, int y)
{
    int px = findParent(x);
    int py = findParent(y);
    if(px == py) return;
    /// cout << px << " " << py << endl;
    if(rankParent[px] < rankParent[py])
        parent[px] = py;
    else if(rankParent[px] > rankParent[py])
        parent[py] = px;
    else{
        parent[py] = px;
        rankParent[px]++;
    }
}

void printSet(int n)
{
    for(int i=0; i<n; i++){
        printf("Node is %d Parent is %d Rank is %d\n", i, parent[i], rankParent[i]);
    }
}

int kruskal(int n)
{
    initializeSet(n);
    sort(edge.begin(), edge.end());
    int sz = edge.size();
    int ans = 0;
    for(int i=0; i<sz; i++)
    {
        if(findParent(edge[i].ss.ff) != findParent(edge[i].ss.ss))
        {
            /// union
            unionSet(parent[edge[i].ss.ff], parent[edge[i].ss.ss]);
            /// cout << edge[i].ss.ff << " " << edge[i].ss.ss << endl;
            ans += edge[i].ff;
        }
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
        piii e;
        cin >> e.ss.ff >> e.ss.ss >> e.ff;
        edge.push_back(e);
    }
    cout << "MST Cost " << kruskal(vertex) << endl;

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
1 2 7
1 3 4
1 4 1
2 4 8
3 4 3
2 5 6
4 5 6
Output: 16

6 9
1 2 6
1 5 5
2 5 7
2 3 1
5 4 14
3 5 8
3 6 2
3 4 5
4 6 3
Output: 17
*/
