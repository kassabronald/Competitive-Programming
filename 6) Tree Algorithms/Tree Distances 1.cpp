#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'

vector<int> dist_1(200001);
vector<int> dist_2(200001);
vector<bool> visited(200001, false);
int bfs(int u, vector<vector<int>> &adj, int which)
{
    int curr = u;
    int last = -1;
    queue<int> q;
    q.push(u);
    while (!q.empty())
    {
        curr = q.front();
        visited[curr] = true;
        q.pop();
        for (int i : adj[curr])
        {
            if (!visited[i])
            {
                q.push(i);
                if (which == 1)
                {
                    dist_1[i] = dist_1[curr] + 1;
                }
                else if (which == 2)
                {
                    dist_2[i] = dist_2[curr] + 1;
                }
                last = i;
            }
        }
    }
    int n = (int)adj.size();
    for (int i = 0; i <= n; i++)
    {
        visited[i] = false;
    }

    return last;
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
    if (n == 1)
    {
        cout << 0 << endl;
    }
    else
    {
        int a = bfs(0, adj, 0);
        int b = bfs(a, adj, 1);
        int c = bfs(b, adj, 2);
        for (int i = 0; i < n; i++)
        {
            cout << max(dist_1[i], dist_2[i]) << " ";
        }
        cout << endl;
    }

    return 0;
}