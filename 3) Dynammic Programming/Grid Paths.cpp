
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
    vector<vector<ll>> vec(n, vector<ll>(n, 0));
    vector<vector<ll>> dp(n, vector<ll>(n, 0));
    for (ll i = 0; i < n; i++)
    {
        for (ll j = 0; j < n; j++)
        {
            char k;
            cin >> k;
            if (k == '.')
            {
                vec[i][j] = 1;
            }
            else
            {
                vec[i][j] = 0;
            }
        }
    }
    // dp[i][j]: number of path to reach(i,j).
    // want dp[n-1][n-1]
    // guess where I was before reaching (i,j): 2 choices (i-1,j)or(i,j-1)
    if (vec[0][0] == 0)
    {
        dp[0][0] = 0;
        cout << 0 << endl;
    }
    else
    {
        dp[0][0] = 1;
    }
    if (dp[0][0] == 1)
    {
        for (ll i = 1; i < n; i++)
        {
            if (vec[i][0] == 1)
            {
                dp[i][0] = 1;
            }
            else
            {
                dp[i][0] = 0;
                break; // cause u cant reach whats beyond
            }
        }
        for (ll i = 1; i < n; i++)
        {
            if (vec[0][i] == 1)
            {
                dp[0][i] = 1;
            }
            else
            {
                dp[0][i] = 0;
                break;
            }
        }
        for (ll i = 1; i < n; i++)
        {
            for (ll j = 1; j < n; j++)
            {
                if (vec[i][j] != 0)
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
                }
            }
        }
        cout << dp[n - 1][n - 1] << endl;
    }

    return 0;
}