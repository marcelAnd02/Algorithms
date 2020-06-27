#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 509;
int dist[N][N], INF = 1e9;

bool floyd_warshall()
{
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            for(int k = 1; k <= n; k++)
                dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
    for(int i = 1; i <= n; i++)
        if(dist[i][i] < 0) // if this is true there is a negative cycle in the graph
            return false;
    return true;
}

void set_dist()
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++)
            dist[i][j] = INF;
    for(int i = 0; i < N; i++)
        dist[i][i] = 0;
}

int main()
{
    cin >> n >> m; // number of vertices and edges of a directed graph
    set_dist();
    for(int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        dist[a][b] = x;
    }
    floyd_warshall();
    /*
    dist contains shortest paths between each vertex and all other vertices (if there is no negative cycle)
    */


    return 0;
}
