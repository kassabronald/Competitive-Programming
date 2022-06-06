#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

vector<int> maxiChild(200001, 0);
// maxichild is used because if we do include i in the diameter
// then we need the deepest Grandchild from the 2 deepest child of i.
void dfs(int u, int p, vector<vector<int>> &dp, vector<vector<int>> &adj)
{
    int maxx = 0;
    int which = -1;
    bool leaf = true;
    for (int i : adj[u])
    {
        if (i != p)
        {
            leaf = false;
            dfs(i, u, dp, adj);
            dp[u][0] = max({dp[i][0], dp[i][1], dp[u][0]});
            if (maxiChild[i] >= maxx)
            {
                maxx = maxiChild[i];
                which = i;
                maxiChild[u] = maxiChild[i] + 1;
            }
        }
    }
    if (leaf)
    {
        dp[u][0] = dp[u][1] = 0;
        return;
    }
    int maxx2 = 0;
    for (int i : adj[u])
    {
        if (i != p)
        {
            if (maxiChild[i] > maxx2 && i != which)
            {
                maxx2 = maxiChild[i];
            }
        }
    }
    dp[u][1] = maxx + maxx2 + 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    int start = -1;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (adj[a].size() > 1)
        {
            start = a;
        }
        if (adj[b].size() > 1)
        {
            start = b;
        }
    }
    if (start == -1)
    {
        cout << (n - 1) << endl;
    }
    else
    {
        vector<vector<int>> dp(n, vector<int>(2, 0));
        // dp[i][0] = diameter of the subtree rooted at i if we do not take i
        // dp[i][1] = diameter of the subtree rooted at i if we do take i
        dfs(start, -1, dp, adj);
        cout << max(dp[start][0], dp[start][1]) << endl;
    }

    return 0;
}