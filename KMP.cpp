#include <bits/stdc++.h>

using namespace std;
string word, pattern;
const int N = 1e6 + 9;
int pref_suf[N], cnt;

void KMP(string St)
{
    int t = 0;
    for(int i = 2; i < St.size(); i++)
    {
        while(t > 0 && St[t + 1] != St[i])
            t = pref_suf[t];
        if(St[t + 1] == St[i])
            t++;
        pref_suf[i] = t;
    }
}

int main()
{
    cin >> word >> pattern;
    KMP("$" + pattern + "$" + word);
    for(int i = 0; i < pattern.size() + word.size() + 2; i++)
        if(pref_suf[i] == pattern.size())
            cnt++;
    cout << cnt; // number of occurrences of pattern in a text

    return 0;
}
