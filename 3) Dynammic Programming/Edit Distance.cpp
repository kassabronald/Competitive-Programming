#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const long long MAXVAL = 10000000;
long long arr[MAXVAL];
const ll mod = 1e9 + 7;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    // dp[i][j]: min edit distance for s1[0:i] and s2[0:j];
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = min(dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
            }
            else
            {
                dp[i][j] = min(1 + dp[i - 1][j - 1], min(1 + dp[i - 1][j], 1 + dp[i][j - 1]));
            }
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}