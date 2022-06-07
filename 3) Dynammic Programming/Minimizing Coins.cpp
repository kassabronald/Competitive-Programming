
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const ll mod = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n, x;
    cin >> n >> x;
    vector<ll> vec(n, 0);
    vector<ll> dp(x + 1, 0);
    for (ll i = 0; i < n; i++)
    {
        cin >> vec[i];
        if (vec[i] <= x)
        {
            dp[vec[i]] = 1;
        }
    }
    for (ll i = 1; i <= x; i++)
    { // subproblems
        ll mini = 1e9 + 7;
        for (ll j = 0; j < n; j++)
        { // num of choices
            if (i - vec[j] >= 0)
            {
                mini = min(mini, dp[i - vec[j]] + 1);
            }
        }
        dp[i] = mini;
    }

    (dp[x] != 1e9 + 7) ? cout << dp[x] : cout << -1;
    cout << endl;

    return 0;
}