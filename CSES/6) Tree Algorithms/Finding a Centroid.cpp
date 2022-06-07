#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const int MAXN = 2e5 + 5;
vector<vector<int>> adj(MAXN);

void dfs(int u, int p, vector<int> &d)
{
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u, d);
            d[u] += d[v];
        }
    }
}

int find_centroid(int u, int p, vector<int> &d, int n)
{
    for (int v : adj[u])
    {
        if (v == p)
        {
            continue;
        }
        if (d[v] > (n / 2))
        {
            return find_centroid(v, u, d, n);
        }
    }
    return u;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int i = 0;
    vector<int> d(n, 1);
    dfs(0, -1, d);
    cout << find_centroid(0, -1, d, n) + 1 << endl;

    return 0;
}