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
  int n, m;
  int mod = 1e9 + 7;
  cin >> n >> m;
  vector<int> v(n);
  for (int i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  // dp[i][j] = number of arrays ending at i with v[i] = j.
  // dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1] + dp[i-1][j]
  vector<vector<int>> dp(n, vector<int>(m + 1, 0));
  if (v[0] == 0)
  {
    for (int i = 1; i <= m; i++)
    {
      dp[0][i] = 1;
    }
  }
  else
  {
    dp[0][v[0]] = 1;
  }
  for (int i = 1; i < n; i++)
  {
    for (int j = 1; j <= m; j++)
    {
      if (v[i] != 0)
      {
        if (j == v[i])
        {
          dp[i][j] = (dp[i][j] + dp[i - 1][j - 1] + (j < m ? dp[i - 1][j + 1] : 0) + dp[i - 1][j]) % mod;
        }
      }
      else
      {
        dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
        dp[i][j] = (dp[i][j] + (j > 0 ? dp[i - 1][j - 1] : 0)) % mod;
        dp[i][j] = (dp[i][j] + (j < m ? dp[i - 1][j + 1] : 0)) % mod;
      }
    }
  }
  int ans = 0;
  if (v[n - 1] == 0)
  {
    for (int k = 1; k <= m; k++)
    {
      ans = (ans + dp[n - 1][k]) % mod;
    }
  }
  else
  {
    ans = dp[n - 1][v[n - 1]];
  }
  cout << ans << endl;

  return 0;
}
