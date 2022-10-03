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
    int n, a, b;
    cin >> n >> a >> b;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        pref[i] = v[i] + pref[i - 1];
    }
    int ans = -1e18;
    multiset<int> s;
    for (int i = a; i <= n; i++)
    {
        if (i > b)
        {
            s.erase(s.find(pref[i - b - 1]));
        }
        s.insert(pref[i - a]);
        ans = max(ans, pref[i] - *s.begin());
    }
    cout << ans << endl;

    return 0;
}
