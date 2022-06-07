#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

template <typename T>
ostream &operator<<(ostream &os, const vector<T> vec)
{
    int n = vec.size();
    if (n == 0)
    {
        os << "[]" << endl;
        return os;
    }
    os << "[";
    for (int i = 0; i < n - 1; i++)
    {
        os << vec[i] << ", ";
    }
    os << vec[n - 1] << "]" << endl;
    return os;
}

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
        for (int v = 2; v <= n; v++)
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

int get_dist(int a, int b)
{

    if (depth[a] < depth[b])
    {
        swap(a, b);
    }
    int res = 0;
    int k = depth[a] - depth[b];
    res += k;
    for (int bit = 20; bit >= 0; bit--)
    {
        if (k & (1 << bit))
        {
            a = up[a][bit];
        }
    }
    if (a == b)
    {
        return res;
    }
    int tmp = 0;
    for (int bit = 20; bit >= 0; bit--)
    {
        if (up[a][bit] != up[b][bit])
        {
            a = up[a][bit];
            b = up[b][bit];
            tmp += (1 << bit);
        }
    }
    tmp *= 2;
    res += tmp;
    return res + 2;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<vector<int>> adj(n + 1);
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1, -1, adj);
    preProcess(n, adj);
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << get_dist(a, b) << endl;
    }

    return 0;
}