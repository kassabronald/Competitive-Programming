#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

bool compare(pair<pair<ll, ll>, ll> p1, pair<pair<ll, ll>, ll> p2)
{
    return p1.first.second < p2.first.second;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> vec(n);
    vector<ll> finish(n);
    for (ll i = 0; i < n; i++)
    {
        ll j, k, l;
        cin >> j >> k >> l;
        vec[i] = {{j, k}, l};
        finish[i] = k;
    }
    sort(vec.begin(), vec.end(), compare);
    sort(finish.begin(), finish.end());

    vector<ll> dp(n, 0); // dp[i]: max amount one can get by considering projects 0...i
    // dp[i] = max(dp[last possible idx]+value[i], value[i])
    dp[0] = vec[0].second;
    ll maxi = dp[0];
    for (ll i = 1; i < n; i++)
    {
        int idx = lower_bound(finish.begin(), finish.end(), vec[i].first.first) - finish.begin();
        if (idx != 0)
        {
            dp[i] = max(dp[i - 1], dp[idx - 1] + vec[i].second); // always take cases where we take number at i or no!
        }
        else if (idx == 0)
        {
            dp[i] = max(vec[i].second, dp[i - 1]);
        }
        maxi = max(dp[i], maxi);
    }
    cout << maxi << endl;

    return 0;
}