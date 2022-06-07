#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()
int INF = (1ll << 59);

// graph class.
struct edge
{
    // add if weighted + constructor!
    int w;
    int u, v;
    edge() {}
    edge(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

struct node
{
    vector<edge> edges;
};

struct graph
{
    vector<node> nodes;
    int n;
    vector<edge> edges;
    graph(int _n) : n(_n) { nodes.resize(n); }

    void add_edge(int u, int v, int w)
    {
        edge e(u, v, w);
        edge ep(v, u, w);
        nodes[u].edges.push_back(e);
        // add if undirected.
        nodes[v].edges.push_back(ep);
        edges.push_back(ep);
        edges.push_back(e);
    }

    vector<vector<int>> allPairsShortestPath()
    {
        vector<vector<int>> ans(n, vector<int>(n, INF));
        for (int i = 0; i < n; i++)
        {
            ans[i][i] = 0;
            for (auto &e : nodes[i].edges)
            {
                ans[i][e.v] = min(ans[i][e.v], e.w);
            }
        }
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    ans[i][j] = min(ans[i][j], ans[i][k] + ans[k][j]);
                }
            }
        }
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.add_edge(u, v, w);
    }
    vector<vector<int>> ans = g.allPairsShortestPath();
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        cout << (ans[u][v] == INF ? -1 : ans[u][v]) << endl;
    }

    return 0;
}