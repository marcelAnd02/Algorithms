#include <bits/stdc++.h>

using namespace std;
int n, q;
int BASE = (1 << 30);

struct Node
{
    Node *left, *right;
    long long sum;
    Node() : left(NULL), right(NULL), sum(0) {}
    ~Node()
    {
        delete left;
        delete right;
    }
    Node *L()
    {
        if(left == NULL)
            left = new Node();
        return left;
    }
    Node *R()
    {
        if(right == NULL)
            right = new Node();
        return right;
    }

    long long rn_add(int p, int a, int b, long long x)
    {
        if(a > p || b < p)
            return sum;
        if(a == b)
            return sum = sum + x;
        return sum = L() -> rn_add(p, a, (a + b) / 2, x) + R() -> rn_add(p, (a + b) / 2 + 1, b, x);
    }

    long long rn_read(int x, int y, int a, int b)
    {
        if(a > y || b < x)
            return 0;
        if(a >= x && b <= y)
            return sum;
        return L() -> rn_read(x, y, a, (a + b) / 2) + R() -> rn_read(x, y, (a + b) / 2 + 1, b);
    }
};

main()
{
    cin >> n >> q;
    Node tree;
    for(int z = 0; z < q; z++)
    {
        char query;
        cin >> query;
        if(query == 'd') // add some value to a particular element
        {
            int pos, val;
            cin >> pos >> val;
            tree.rn_add(pos, 1, BASE, val);
        }
        else // read sum on range
        {
            int a, b;
            cin >> a >> b;
            cout << tree.rn_read(a, b, 1, BASE);
        }
        
    }

    return 0;
}
