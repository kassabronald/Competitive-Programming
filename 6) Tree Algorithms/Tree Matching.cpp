#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

void dfs(int v, int p, vector<vector<int>> &adj, vector<vector<int>> &dp)
{
    for (int to : adj[v])
    {
        if (to != p)
        {
            dfs(to, v, adj, dp);
            dp[v][0] += max(dp[to][0], dp[to][1]);
        }
    }
    for (int to : adj[v])
    {
        if (to != p)
        {
            dp[v][1] = max(dp[v][1], dp[to][0] + 1 + dp[v][0] - max(dp[to][0], dp[to][1]));
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vector<vector<int>> dp(n, vector<int>(2, 0));
    // dp[i][0] =  represent the maximum matching of the subtree rooted at i such that we don't take any edges
    // leading to some child of i.
    // dp[i][1] = represent the maximum matching of the subtree rooted at i such that 1 edge
    // leading to some child of i.

    vector<bool> visited(n, false);
    dfs(0, -1, adj, dp);
    cout << max(dp[0][0], dp[0][1]) << endl;

    return 0;
}