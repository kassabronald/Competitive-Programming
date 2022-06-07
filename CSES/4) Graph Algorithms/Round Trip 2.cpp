#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

// graph class.
struct edge
{
    // add if weighted + constructor!
    //  int w;
    int u, v;
    edge() {}
    edge(int _u, int _v) : u(_u), v(_v) {}
};

struct node
{
    int color = -1;

    vector<edge> edges;
};

struct graph
{
    vector<node> nodes;
    int n;
    vector<edge> edges;
    graph(int _n) : n(_n)
    {
        nodes.resize(n);
    }

    void add_edge(int u, int v)
    {
        edge e(u, v);
        edge ep(v, u);
        nodes[u].edges.push_back(e);
        // add if undirected.
        // nodes[v].edges.push_back(ep);
        // edges.push_back(ep);
        edges.push_back(e);
    }

    void dfs()
    {
        vector<int> parent(n, -1);
        int ans = -1;
        for (int i = 0; i < n; i++)
        {
            if (nodes[i].color == -1)
            {
                ans = dfs_util(i, parent);
                if (ans != -1)
                {
                    break;
                }
            }
        }
        if (ans == -1)
        {
            cout << "IMPOSSIBLE" << endl;
            return;
        }
        vector<int> cycle;
        cycle.push_back(ans);
        int cur = parent[ans];
        while (cur != ans)
        {
            cycle.push_back(cur);
            cur = parent[cur];
        }
        cycle.push_back(cur);
        cout << (int)cycle.size() << endl;
        reverse(all(cycle));
        for (int i : cycle)
        {
            cout << i + 1 << " ";
        }
    }
    int dfs_util(int u, vector<int> &parent)
    {
        nodes[u].color = 0;
        for (auto &e : nodes[u].edges)
        {
            if (nodes[e.v].color == 1)
            {
                continue;
            }
            if (nodes[e.v].color == -1)
            {
                parent[e.v] = u;
                int res = dfs_util(e.v, parent);
                if (res != -1)
                {
                    return res;
                }
            }
            else
            {
                parent[e.v] = u;
                return u;
            }
        }
        nodes[u].color = 1;
        return -1;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (u != v)
        {
            g.add_edge(u, v);
        }
    }
    g.dfs();

    return 0;
}