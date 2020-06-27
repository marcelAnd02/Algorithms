#include <bits/stdc++.h>

using namespace std;
int n, q;
const int Nt = (1 << 21) + 9;
int BASE = (1 << 20);
int tree[Nt];

int rn_add(int v, int p, int a, int b, int x)
{
    if(a > p || b < p)
        return tree[v];
    if(a == b)
        return tree[v] = tree[v] + x;
    return tree[v] = rn_add(2*v, p, a, (a + b) / 2, x) + rn_add(2*v + 1, p, (a + b) / 2 + 1, b, x);
}

int rn_read(int v, int x, int y, int a, int b)
{
    if(a > y || b < x)
        return 0;
    if(a >= x && b <= y)
        return tree[v];
    return rn_read(2*v, x, y, a, (a + b) / 2) + rn_read(2*v + 1, x, y, (a + b) / 2 + 1, b);
}

void pre_process()
{
    for(int i = BASE - 1;  i > 0; i--)
        tree[i] = tree[2*i] + tree[2*i + 1];
}

main()
{
    cin >> n >> q; // number of elements and number of queries
    for(int i = 0; i < n; i++)
        cin >> tree[i + BASE]; // initial values of elements
    pre_process();
    for(int z = 0; z < q; z++)
    {
        char query;
        cin >> query;
        if(query == 'd') // add some value to a particular element
        {
            int pos, val;
            cin >> pos >> val;
            rn_add(1, pos, 1, BASE, val);
        }
        else // read sum on a given range
        {
            int a, b;
            cin >> a >> b;
            cout << rn_read(1, a, b, 1, BASE);
        }
        
    }


    return 0;
}
