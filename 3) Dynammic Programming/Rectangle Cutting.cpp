#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];

int solve(int a, int b)
{
    if (a == b)
    {
        return 0;
    }
    else if (a < b)
    {
        return 1 + solve(a, b - a);
    }
    else
    {
        return 1 + solve(a - b, b);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    // cout << solve(a, b) << endl;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; i++)
    {
        for (int j = 1; j <= b; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1e9;
                for (int k = 1; k < i; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
                }
                for (int k = 1; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k] + 1);
                }
            }
        }
    }
    cout << dp[a][b] << endl;

    return 0;
}