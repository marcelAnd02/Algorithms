#include <bits/stdc++.h>

using namespace std;
int n, m, q;
const int N = 1e6 + 9;
int F[N];

int fnd(int x)
{
    if(F[x] == x)
        return x;
    F[x] = fnd(F[x]);
    return F[x];
}

void unite(int a, int b)
{
    int fth_a = fnd(a);
    int fth_b = fnd(b);
    if(fth_a == fth_b)
        return;
    F[fth_b] = fth_a;
}

int main()
{
    cin >> n >> m; // number of elements and number of connect operations
    for(int i = 1; i <= n; i++)
        F[i] = i;
    for(int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b; // connect two elements
        unite(a, b);
    }
    cin >> q;
    for(int z = 0; z < q; z++)
    {
        int a, b;
        cin >> a >> b; // check if elements are directly or indirectly connected
        if(F[a] == F[b])
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";
    }


    return 0;
}
