#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    if (n * (n + 1) % 4 != 0)
    {
        cout << 0 << endl;
    }
    else
    {
        int m = n * (n + 1) / 4;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // dp[i][j] = do there exists a non empty subset A of 1..i st sum(A) = j

        dp[1][1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = (dp[i][j] + dp[i - 1][j] + (j - i >= 0 ? dp[i - 1][j - i] : 0)) % mod;
            }
        }
        cout << dp[n][m] << endl;
    }

    return 0;
}
