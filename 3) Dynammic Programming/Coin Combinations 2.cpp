
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
    }
    dp[0] = 1;
    for (ll j = 0; j < n; j++)
    {
        for (ll i = 1; i <= x; i++)
        {
            if (i - vec[j] >= 0)
            {
                dp[i] = (dp[i] + dp[i - vec[j]]) % mod;
            }
        }
    }

    cout << dp[x];
    cout << endl;

    return 0;
}
