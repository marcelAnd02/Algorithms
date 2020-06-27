#include <bits/stdc++.h>

using namespace std;
int n, m;
const int N = 1e5 + 9;
vector<int> G[N], Gt[N];
stack<int> st;
vector<bool> vis(N);
vector< vector<int> > str_comp;

void dfs_st(int v)
{
    vis[v] = true;
    for(auto i : G[v])
        if(!vis[i])
            dfs_st(i);
    st.push(v);
}

void SCC(int v)
{
    str_comp[str_comp.size() - 1].push_back(v);
    vis[v] = true;
    for(auto i : Gt[v])
        if(!vis[i])
            SCC(i);
}

int main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        Gt[b].push_back(a);
    }
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfs_st(i);
    fill(vis.begin(), vis.end(), false);
    while(!st.empty())
    {
        int v = st.top();
        st.pop();
        if(!vis[v])
        {
            vector<int> p; str_comp.push_back(p);
            SCC(v);
        }
    }
    cout << str_comp.size() << "\n";
    for(auto vec : str_comp)
    {
        for(auto i : vec)
            cout << i << ' '; // vertices in a Strongly Connected Component
        cout << "\n";
    }


    return 0;
}
