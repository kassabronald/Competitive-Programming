#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const ll mod = 1e9 + 7;

vector<ll> solve(vector<ll> vec, ll idx)
{
    if (idx == vec.size() - 1)
    {
        return {vec[idx]};
    }
    else
    {
        vector<ll> res = solve(vec, idx + 1);
        for (ll x : res)
        {
            res.push_back(vec[idx] + x);
        }
        res.push_back(vec[idx]);
        return res;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n;
    vector<ll> vec(n, 0);
    ll tot = 0;
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        tot += vec[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(tot + 1, false));
    for (ll i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    dp[0][vec[0]] = 1;

    set<ll> s;
    s.insert(vec[0]);
    // 0-1 knapsack
    for (ll i = 1; i < n; i++)
    {
        for (ll x = 1; x <= tot; x++)
        {
            if (dp[i - 1][x] == 1)
            {
                dp[i][x] = 1;
            }
            else if (x - vec[i] >= 0)
            {
                dp[i][x] = dp[i][x] | dp[i - 1][x - vec[i]];
            }
            if (dp[i][x] == 1)
            {
                s.insert(x);
            }
        }
    }
    cout << s.size() << endl;
    for (auto it = s.begin(); it != s.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}