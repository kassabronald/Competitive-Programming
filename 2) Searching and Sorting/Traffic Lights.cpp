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
    int x, n;
    cin >> x >> n;
    multiset<int> s;
    set<int> lights = {0, x};
    s.insert(x);
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        auto pos1 = lights.upper_bound(t);
        auto pos2 = pos1;
        pos2--;
        s.erase(s.find(*pos1 - *pos2));
        s.insert(abs(t - *pos1));
        s.insert(abs(t - *pos2));
        lights.insert(t);
        auto ans = s.end();
        ans--;
        cout << *ans << " ";
    }

    return 0;
}