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
    int n, x;
    cin >> n >> x;
    vector<int> pages(n + 1, 0);
    vector<int> prices(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> prices[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> pages[i];
    }
    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= x; j++)
        {
            if (j - prices[i] >= 0)
            {
                dp[i][j] = max(dp[i - 1][j], pages[i] + dp[i - 1][j - prices[i]]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    cout << dp[n][x] << endl;

    return 0;
}