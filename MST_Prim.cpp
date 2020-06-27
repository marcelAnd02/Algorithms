#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e5 + 9;
vector< pair<int, int> > G[N];
bool vis[N];

int MST(int v)
{
    priority_queue< pair<int, int> > qu;
    int conn = 1, sol = 0;
    while(conn != n)
    {
        vis[v] = true;
        for(auto i : G[v])
            if(!vis[i.first])
                qu.push({-i.second, i.first});
        while(vis[qu.top().second])
            qu.pop();
        v = qu.top().second;
        sol -= qu.top().first;
        conn++;
        qu.pop();
    }
    return sol;
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
    cout << MST(1);

    return 0;
}
