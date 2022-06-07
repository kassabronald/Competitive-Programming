#include <bits/stdc++.h>
using namespace std;
const int mod = 1000 * 1000 * 1000 + 7;

int dp[1 << 20][20];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> YouAreReachableFrom(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        YouAreReachableFrom[--b].push_back(--a);
    }

    dp[1][0] = 1;
    for (int mask = 1; mask < (1 << n); mask += 2)
    {
        for (int i = 1; i < n; i++)
            if (mask & (1 << i))
                for (int j : YouAreReachableFrom[i])
                    dp[mask][i] = (dp[mask][i] + dp[mask ^ (1 << i)][j]) % mod;
    }
    cout << dp[(1 << n) - 1][n - 1] << '\n';
    return 0;
}