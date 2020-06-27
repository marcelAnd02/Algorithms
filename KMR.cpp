#include <bits/stdc++.h>

using namespace std;
string word;
const int N = 1e5 + 9, Lg = 19, Asc = 96;
int hash_KMR[Lg][N];

void form_KMR()
{
    int layer = 1, num_hash = 27;
    while((1 << layer) <= n) 
    {
        int curr_lng = (1 << layer);
        set< pair<int, int> > hash_pairs;
        map< pair<int, int>, int > new_hash;
        for(int i = 1; i <= n - curr_lng + 1; i++)
            hash_pairs.insert(make_pair(hash_KMR[layer - 1][i], hash_KMR[layer - 1][i + curr_lng / 2]));
        for(auto it : hash_pairs) 
        {
            new_hash[it] = num_hash;
            num_hash++;
        }
        for(int i = 1; i <= n - curr_lng + 1; i++)
            hash_KMR[layer][i] = new_hash[make_pair(hash_KMR[layer - 1][i], hash_KMR[layer - 1][i + curr_lng / 2])];
        layer++;
    }
}

int main()
{
    cin >> word;
    for(int i = 0; i < word.size(); i++)
        hash_KMR[0][i + 1] = word[i] - Asc;
    form_KMR();
    

    return 0;
}
