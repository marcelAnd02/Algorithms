#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


int main()
{
    ordered_set ordset;
    ordset.insert(3);
    ordset.insert(5);
    ordset.insert(2);

    //returns position of greater or equal value in the sorted set
    cout << ordset.order_of_key(4) << "\n";

    // returns pointer to k-th smallest element in the set
    cout << *ordset.find_by_order(1) << "\n";


    return 0;
}