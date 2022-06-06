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

void dfs(int u, int p, vector<vector<int>> &adj, vector<int> &dp)
{
    for (int i : adj[u])
    {
        if (i != p)
        {
            dfs(i, u, adj, dp);
            dp[u] += dp[i] + 1;
        }
    }
}

int f(int u, vector<vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(u);
    vector<int> dist((int)adj.size(), 0);
    int ans = 0;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        visited[curr] = true;
        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                dist[i] = dist[curr] + 1;
                ans += dist[i];
            }
        }
    }
    return ans;
}
// initially calculate result for root.
// then ans[children] = ans[parent]-sizeOfSubtreeRootedAt[children]+(numberOfNodes-sizeOfSubtreeRootedAt[children]-2)
void bfs(int u, vector<vector<int>> &adj, vector<int> &dp, vector<int> &ans, vector<bool> &visited)
{
    int n = (int)adj.size();
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        visited[curr] = true;
        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                q.push(i);
            }
        }
        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                ans[i] = (ans[i] + ans[curr] - dp[i] + (n - dp[i] - 2));
            }
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
    vector<int> dp(n, 0);
    dfs(0, -1, adj, dp);
    vector<int> ans(n, 0);
    vector<bool> p(n, false);
    ans[0] = f(0, adj, p);
    vector<bool> visited(n, false);
    bfs(0, adj, dp, ans, visited);
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}