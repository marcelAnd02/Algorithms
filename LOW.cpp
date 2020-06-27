#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e5 + 9;
vector<int> G[N];
int low[N], preorder[N], pre_counter = 1;
bool vis[N];

void dfs(int v, int fath)
{
    vis[v] = true;
    preorder[v] = pre_counter;
    low[v] = pre_counter;
    pre_counter++;
    for(auto i : G[v])
    {
        if(i == fath)
            continue;
        if(vis[i])
            low[v] = min(low[v], preorder[i]);
        else
        {
            dfs(i, v);
            low[v] = min(low[v], low[i]);
        }
        
    }
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1, 0);
    for(int i = 1; i <= n; i++)
        cout << low[i] << ' ';


    return 0;
}
