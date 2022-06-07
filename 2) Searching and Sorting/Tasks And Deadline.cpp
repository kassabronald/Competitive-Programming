#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

bool check(ll mid, vector<ll> &v, ll t)
{
    ll tot = 0;
    for (ll i = 0; i < v.size(); ++i)
    {
        tot += (mid / v[i]);
    }
    return tot >= t;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    ll t = 0;
    ll res = 0;
    for (pair<ll, ll> p : v)
    {
        res += (p.second - (t + p.first));
        t += p.first;
    }
    cout << res << endl;

    return 0;
}