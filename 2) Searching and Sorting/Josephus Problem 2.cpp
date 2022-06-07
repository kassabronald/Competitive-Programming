#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    ordered_set s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int cur = 0;
    while (s.size() > 0)
    {
        cur = cur % (int)s.size();
        int removes = (cur + k) % (int)s.size();
        cur = removes;
        auto it = s.find_by_order(removes);
        cout << *it << " ";
        s.erase(it);
    }

    return 0;
}