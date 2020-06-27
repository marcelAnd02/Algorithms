#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e5 + 9;
vector< pair<int, int> > G[N];
long long INF = 1e15 + 9;
vector<long long> dist(N);
bool vis[N];

void dijkstra(int v)
{
    fill(dist.begin(), dist.end(), INF);
    dist[v] = 0;
    set< pair<long long, int> > s;
    s.insert({0, v});
    while(!s.empty())
    {
        v = s.begin() -> second;
        long long curr_dist = s.begin() -> first;
        s.erase(s.begin());
        if(vis[v])
            continue;
        vis[v] = true;
        for(auto i : G[v])
        {
            long long hlpval = curr_dist + i.second;
            if(hlpval < dist[i.first])
            {
                dist[i.first] = hlpval;
                s.insert({hlpval, i.first});
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b, x;
        cin >> a >> b >> x;
        G[a].push_back({b, x});
        G[b].push_back({a, x});
    }
    dijkstra(1);
    for(int i = 1; i <= n; i++)
    {
        if(dist[i] == INF)
            cout << "NO" << "\n"; // there is no path between vertices 1 and i
        else
            cout << dist[i] << "\n"; // shortest path from the first vertex
        
    }

    return 0;
}
