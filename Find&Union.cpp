#include <bits/stdc++.h>

using namespace std;
int n, q;
const int N = 1e5 + 9;
int F[N], comp_size[N];

int fnd(int x)
{
    if(F[x] == x)
        return x;
    F[x] = fnd(F[x]);
    return F[x];
}

void unite(int a, int b)
{
    int rep_a = fnd(a);
    int rep_b = fnd(b);
    if(rep_a == rep_b)
        return;
    if(comp_size[rep_a] < comp_size[rep_b])
        swap(rep_a, rep_b);
    comp_size[rep_a] += comp_size[rep_b];
    F[rep_b] = rep_a;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        F[i] = i;
        comp_size[i] = 1;
    }
    for(int z = 0; z < q; z++) 
    {
        int a, b;
        cin >> a >> b;
        unite(a, b);
    }


    return 0;
}
