#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
const int MAXN = 2e5 + 5;
vector<vector<int>> adj(MAXN);
vector<int> colors(MAXN);
vector<map<int, int>> m(MAXN);
vector<int> ans(MAXN);

void merge(map<int, int> &m1, map<int, int> &m2)
{
    if ((int)m1.size() > (int)m2.size())
    {
        swap(m1, m2);
    }
    for (auto it : m1)
    {
        m2[it.first] += it.second;
    }
    m1.clear();
}

void dfs(int u, int p)
{
    for (int v : adj[u])
    {
        if (v != p)
        {
            dfs(v, u);
            merge(m[v], m[u]);
        }
    }
    ans[u] = (int)m[u].size();
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> colors[i];
        m[i][colors[i]]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}