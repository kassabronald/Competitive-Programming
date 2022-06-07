#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> up(2e5 + 10, vector<int>(21, 0));
vector<int> depth(2e5 + 10);

void dfs(int u, int p, vector<vector<int>> &adj)
{
    for (int i : adj[u])
    {
        if (i != p)
        {
            up[i][0] = u;
            depth[i] = depth[u] + 1;
            dfs(i, u, adj);
        }
    }
}

void preProcess(int n, vector<vector<int>> &adj)
{

    for (int i = 1; i <= 20; i++)
    {
        for (int v = 1; v < n; v++)
        {
            // my 2^ith parent is the 2^(i-1)st parent of my 2^(i-1)st parent.
            // ex: my 2^5 = 32 parent is the 2^4 = 16th parent of my 16th parent.
            up[v][i] = up[up[v][i - 1]][i - 1];
        }
    }
    // basically get all parents that are at powers of 2.
    // my grandparent is parent of my parent, my 4th parent is the 2nd parent of my parent
    // my 8th parent is the 4th parent of my grandparent and so on.
}

int get_lca(int a, int b)
{

    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    int k = depth[a] - depth[b];
    for (int bit = 20; bit >= 0; bit--)
    {
        if (k & (1 << bit))
        {
            a = up[a][bit];
        }
    }
    if (a == b)
    {
        return a;
    }
    for (int bit = 20; bit >= 0; bit--)
    {
        if (up[a][bit] != up[b][bit])
        {
            a = up[a][bit];
            b = up[b][bit];
        }
    }
    return (up[a][0]);
}

void dfs_for_path(int u, int p, vector<int> &ans, vector<vector<int>> &adj, vector<int> &val)
{
    ans[u] = val[u];
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs_for_path(v, u, ans, adj, val);
            ans[u] = (ans[u] + ans[v]);
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    vector<int> val(n);
    for (int i = 2; i <= n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(0, -1, adj);
    preProcess(n, adj);
    vector<int> ans(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (depth[a] < depth[b])
        {
            swap(a, b);
        }
        int k = get_lca(a, b);
        if (k == b)
        {
            if (up[k][0] != b)
            {
                val[up[k][0]]--;
            }
            val[a]++;
        }
        else
        {
            val[b]++;
            val[a]++;
            val[k]--;
            if (up[k][0] != k)
            {
                val[up[k][0]]--;
            }
        }
    }
    dfs_for_path(0, -1, ans, adj, val);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}