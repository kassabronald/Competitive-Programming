#include <bits/stdc++.h>
using namespace std;

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
    set<int> s;
    for (int i = 1; i <= n; i++)
    {
        s.insert(i);
    }
    int cur = 1;
    while (s.size() != 1)
    {
        auto it = s.upper_bound(cur);
        if (it == s.end())
        {
            it = s.begin();
        }
        cout << *it << " ";
        auto next = it;
        next++;
        if (next == s.end())
        {
            next = s.begin();
        }
        cur = *next;
        s.erase(it);
    }
    cout << *s.begin() << endl;

    return 0;
}