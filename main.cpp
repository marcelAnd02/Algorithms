#include <bits/stdc++.h>

using namespace std;
int n;
const int N = 1e5 + 9;
int nums[N];

int bin_search(int val)
{
    int p = 1, k = n, mid;
    while(p < k) 
    {
        mid = (p + k) / 2;
        if(nums[mid] < val)
            p = mid + 1;
        else
            k = mid;
    }
    return p;
}

/*
int bin_search(int val)
{
    int p = 1, k = n, mid;
    while(p < k)
    {
        mid = (p + k + 1) / 2;
        if(nums[mid] <= val)
            p = mid;
        else
            k = mid - 1;
    }
    return p;
}
*/

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> nums[i]; // array of sorted numbers
    cout << bin_search(5);


    return 0;
}