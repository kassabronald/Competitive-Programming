#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int32_t main()
{
  int n;
  cin >> n;
  vector<int> x(n);
  int sum = 0;
  for (int &v : x)
  {
    cin >> v;
    sum += v;
  }

  vector<vector<int>> dp(n, vector<int>(n, 0));
  // dp[l][r] : max difference between score[1] and score[2] if game is played between l and r (so player 1 starts)
  for (int l = n - 1; l >= 0; l--)
  {
    for (int r = l; r < n; r++)
    {
      if (l == r)
      {
        dp[l][r] = x[l];
      }
      else
      {
        dp[l][r] = max(x[l] - dp[l + 1][r],  // took element on the left so player 2 starts so score is -dp[l+1][r]
                       x[r] - dp[l][r - 1]); // took element on the right
      }
    }
  }
  cout << (sum + dp[0][n - 1]) / 2 << endl;
}
