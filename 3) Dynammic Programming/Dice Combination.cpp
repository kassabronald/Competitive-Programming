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
    ll n;
    cin >> n;
    vector<ll> dp(n + 1, 0);
    for (ll i = 1; i <= 6; i++)
    {
        dp[i] = 1;
    }
    dp[1] = 1;
    for (ll i = 2; i <= n; i++)
    {
        for (ll j = 1; j <= 6; j++)
        {
            if (i > j)
            {
                dp[i] = (dp[i] + dp[i - j]) % mod;
            }
        }
    }
    cout << dp[n] << endl;

    return 0;
}