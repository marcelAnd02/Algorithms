BELLMAN-FORD


#include <bits/stdc++.h>

using namespace std;
int n, m, st, INF = 1e9;
const int N = 509;
vector< tuple<int, int, int> > edg;
vector<int> dist(N);

bool bellman_ford(int v)
{
    dist[v] = 0;
    for(int i = 1; i < n; i++)
        for(auto curr : edg)
            if(dist[get<0>(curr)] < INF)
                dist[get<1>(curr)] = min(dist[get<1>(curr)], dist[get<0>(curr)] + get<2>(curr));
    for(auto curr : edg)
        if(dist[get<1>(curr)] > dist[get<0>(curr)] + get<2>(curr)) // if this is true there is a negative cycle in the graph
            return false;
    return true;
}

int main()
{
    cin >> n >> m >> st; // number of vertices, edges, starting vertex
    fill(dist.begin(), dist.end(), INF);
    for(int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x; // vertices a and b are connected by an edge with weitgh x
        edg.push_back(make_tuple(a, b, x));
    }
    bellman_ford();
    /*
    dist contains shortest paths from each vertex to all other vertices(if there is not negative cycle)
    */


    return 0;
}
