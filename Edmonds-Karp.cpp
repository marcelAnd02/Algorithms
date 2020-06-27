#include <bits/stdc++.h>

using namespace std;
int n, m, p, k;
const int N = 509;
vector<int> G[N];
int cap[N][N];
vector<int> path(N);

int bfs(int v)
{
    vector<bool> vis(N);
    fill(path.begin(), path.end(), 0);
    queue< pair<int, int> > qu;
    qu.push({v, INT_MAX});
    while(!qu.empty())
    {
        v = qu.front().first;
        int fl_akt = qu.front().second;
        qu.pop();
        vis[v] = true;
        for(auto i : G[v])
        {
            if(!vis[i] && cap[v][i] > 0)
            {
                int n_fl = min(fl_akt, cap[v][i]);
                path[i] = v;
                if(i == k)
                    return n_fl;
                qu.push({i, n_fl});
            }
        }
    }
    return 0;
}

int max_flow()
{
    int ov_flow = 0;
    while(true)
    {
        int akt_flow = bfs(p);
        if(akt_flow == 0)
            break;
        ov_flow += akt_flow;
        int cur_vert = k;
        while(cur_vert != p)
        {
            int prev_vert = path[cur_vert];
            cap[prev_vert][cur_vert] -= akt_flow;
            cap[cur_vert][prev_vert] += akt_flow;
            cur_vert = prev_vert;
        }
    }
    return ov_flow;
}

int main()
{
    cin >> n >> m >> p >> k; // number of vertices, number of edges, source vertex, sink vertex
    for(int i = 0; i < m; i++)
    {
        int a, b, x; // edge between a and b and its capacity x
        cin >> a >> b >> x;
        G[a].push_back(b);
        G[b].push_back(a);
        cap[a][b] = x;
    }
    cout << max_flow();

    return 0;
}
