#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e5 + 9;
vector<int> G[N]; // DAG
vector<int> sort_vert;
vector<bool> vis(N);

void toposort(int v)
{
    vis[v] = true;
    for(auto i : G[v])
        if(!vis[i])
            toposort(i);
    sort_vert.push_back(v);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            toposort(i);
    reverse(sort_vert.begin(), sort_vert.end());
    for(auto i : sort_vert)
        cout << i << ' ';

    return 0;
}
