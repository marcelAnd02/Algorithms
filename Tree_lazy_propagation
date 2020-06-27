#include <bits/stdc++.h>

using namespace std;
int n, q;
const int Nt = (1 << 21) + 9;
int BASE = (1 << 20);
tuple<int, bool, int> tree[Nt];

void tree_push(int v, int rn_b, int rn_f)
{
    if(v >= BASE)
        return;
    get<1>(tree[v]) = false;
    get<1>(tree[2*v]) = true;
    get<1>(tree[2*v + 1]) = true;
    get<2>(tree[2*v]) += get<2>(tree[v]);
    get<2>(tree[2*v + 1]) += get<2>(tree[v]);
    get<0>(tree[v]) += (long long)get<2>(tree[v]) * (rn_f - rn_b + 1);
    get<2>(tree[v]) = 0;
}

int rn_add(int v, int x, int y, int a, int b, int val)
{
    if(a > y || b < x)
        return get<0>(tree[v]) + get<2>(tree[v]) * (b - a + 1);
    if(a >= x && b <= y)
    {
        get<1>(tree[v]) = true;
        get<2>(tree[v]) += val;
        return get<0>(tree[v]) + get<2>(tree[v]) * (b - a + 1);
    }
    if(get<1>(tree[v]))
        tree_push(v, a, b);
    return get<0>(tree[v]) = rn_add(2*v, x, y, a, (a + b) / 2, val) + rn_add(2*v + 1, x, y, (a + b) / 2 + 1, b, val);
}

int rn_read(int v, int x, int y, int a, int b)
{
    if(a > y || b < x)
        return 0;
    if(a >= x && b <= y)
        return get<0>(tree[v]) + get<2>(tree[v]) * (b - a + 1);
    if(get<1>(tree[v]))
        tree_push(v, a, b);
    return rn_read(2*v, x, y, a, (a + b) / 2) + rn_read(2*v + 1, x, y, (a + b) / 2 + 1, b);
}

void pre_process()
{
    for(int i = BASE - 1; i > 0; i--)
        get<0>(tree[i]) = get<0>(tree[2*i]) + get<0>(tree[2*i + 1]);
}

int main()
{
    cin >> n >> q; // number of elements and number of queries
    for(int i = 0; i < n; i++)
        cin >> get<0>(tree[i + BASE]); // initial values of elements
    pre_process();
    for(int z = 0; z < q; z++)
    {
        char query;
        cin >> query;
        if(query == 'd') // add some value on range [a, b]
        {
            int a, b, val;
            cin >> a >> b >> val;
            rn_add(1, a, b, 1, BASE, val);
        }
        else // read some from range [a, b]
        {
            int a, b;
            cin >> a >> b;
            cout << rn_read(1, a, b, 1, BASE) << "\n";
        }
        
    }

    return 0;
}
