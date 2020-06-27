#include <bits/stdc++.h>

using namespace std;
int n, q;
const int N = 1e6 + 9, Lg = 21;
vector<int> T[N];
int jump[Lg][N], depth[N];

void bfs(int v)
{
    queue<int> qu;
    qu.push(v);
    depth[v] = 1;
    while(!qu.empty())
    {
        v = qu.front();
        qu.pop();
        for(auto i : T[v])
            if(depth[i] == 0)
            {
                jump[0][i] = v;
                depth[i] = depth[v] + 1;
                qu.push(i);
            }
        for(int i = 1; i <= 20; i++)
            jump[i][v] = jump[i - 1][jump[i - 1][v]];
    }
}

int dpt_set(int v, int dest)
{
    for(int i = 20; i >= 0; i--)
        if(depth[jump[i][v]] >= dest)
            v = jump[i][v];
    return v;
}

int LCA(int a, int b)
{
    for(int i = 20; i >= 0; i--)
    {
        if(jump[i][a] != jump[i][b])
        {
            a = jump[i][a];
            b = jump[i][b];
        }
    }
    if(jump[0][a] == jump[0][b] && a != b)
        return jump[0][a];
    return a;
}

int main()
{
    cin >> n >> q; // number of vertices and number of queries
    for(int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        T[a].push_back(b);
        T[b].push_back(a);
    }
    bfs(1);
    for(int z = 0; z < q; z++)
    {
        int a, b;
        cin >> a >> b;
        if(depth[a] < depth[b])
            swap(a, b);
        int s1 = b;
        int s2 = dpt_set(a, depth[b]);
        cout << LCA(s1, s2) << "\n";  // LCA of vertices a and b
    }

    return 0;
}
