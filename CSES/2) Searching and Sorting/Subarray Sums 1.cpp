#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool check(ll mid, vector<ll> &v, ll t)
{
    ll tot = 0;
    for (ll i = 0; i < v.size(); ++i)
    {
        tot += (mid / v[i]);
    }
    return tot >= t;
}

struct triplet
{
    ll i, j, k;
    triplet(ll ii, ll jj, ll kk)
    {
        i = ii;
        j = jj;
        k = kk;
    }
};

bool compare(triplet p1, triplet p2)
{
    return p1.i < p2.i;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> v(n);
    vector<ll> pref(n);
    cin >> v[0];
    pref[0] = v[0];
    for (ll i = 1; i < n; i++)
    {
        cin >> v[i];
        pref[i] = pref[i - 1] + v[i];
    }
    ll res = 0;

    for (ll i = 0; i < n; i++)
    {
        if (pref[i] == x || binary_search(pref.begin(), pref.end(), pref[i] - x))
        {
            res++;
        }
    }
    cout << res << endl;

    return 0;
}