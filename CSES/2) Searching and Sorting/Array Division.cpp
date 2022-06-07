#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

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

bool check(vector<ll> &v, ll mid, ll k)
{
    ll summ = 0;
    ll groups = 0;
    for (ll i : v)
    {
        if (i > mid)
        {
            return false;
        }
        if (summ + i > mid)
        {
            summ = 0;
            groups++;
        }
        summ += i;
    }
    if (summ > 0)
    {
        groups++;
    }
    return groups <= k;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    ll maxx = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
        maxx += v[i];
    }
    ll s = 0;
    ll e = maxx;
    while (s < e)
    {
        ll mid = (s + e) >> 1;
        if (check(v, mid, k))
        {
            e = mid;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << s << endl;

    return 0;
}