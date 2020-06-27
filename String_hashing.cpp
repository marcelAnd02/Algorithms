#include <bits/stdc++.h>

using namespace std;
string word;
int MOD7 = 1e9 + 7, BASE = 997;
const int N = 1e6 + 9;
int vhash[N], vpow[N];

int retrieve_hash(int a, int b)
{
    return (MOD7 + vhash[b] - ((long long)vhash[a - 1] * vpow[b - a + 1]) % MOD7) % MOD7;
}

void calc_hash()
{
    for(int i = 1; i <= word.length(); i++)
        vhash[i] = (((long long)vhash[i - 1] * BASE) % MOD7 + word[i - 1]) % MOD7;
}

void calc_pow()
{
    vpow[0] = 1;
    for(int i = 1; i < N; i++)
        vpow[i] = ((long long)vpow[i - 1] * BASE) % MOD7;
}

int main()
{
    cin >> word;
    calc_pow();
    calc_hash();
    //cout << retrieve_hash(5, 5) << ' ' << retrieve_hash(2, 2);

    return 0;
}
