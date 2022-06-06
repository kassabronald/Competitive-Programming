#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

//'b'-'a' --> which number in alphabet
//'4'-'0' --> get int representation

void dfs(int u, vector<bool> &visited, vector<int> &dp, vector<vector<int>> &adj)
{
    visited[u] = true;
    bool leaf = true;
    for (int i : adj[u])
    {
        if (!visited[i])
        {
            leaf = false;
            dfs(i, visited, dp, adj);
            dp[u] += (dp[i] + 1);
        }
    }
    if (leaf)
    {
        dp[u] = 0;
        return;
    }
}

void dfs2(int u, vector<int> &dp, vector<vector<int>> &adj)
{
    for (int i : adj[u])
    {
        dfs2(i, dp, adj);
        dp[u] += (dp[i] + 1);
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    for (int i = 1; i < n; i++)
    {
        int a;
        cin >> a;
        a--;
        adj[a].push_back(i);
    }
    vector<int> dp(n, 0);
    vector<bool> visited(n, false);
    // dfs(0,visited,dp,adj);
    dfs2(0, dp, adj);
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << " ";
    }
    // dp[i] = number of subordinate of subtree rooted at i.
    // dp[i] = sum(dp[u]: u in adj[i])

    return 0;
}