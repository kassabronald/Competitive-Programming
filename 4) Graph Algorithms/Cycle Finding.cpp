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
        //  nodes[v].edges.push_back(ep);
        // edges.push_back(ep);
        edges.push_back(e);
    }

    void BellmanFord(int s)
    {
        vector<int> dist(n, INF);
        dist[s] = 0;
        vector<int> parent(n);
        for (int i = 0; i <= n - 1; i++)
        {
            for (auto &e : edges)
            {
                int u = e.u;
                int v = e.v;
                int w = e.w;
                if (dist[v] > dist[u] + w)
                {
                    dist[v] = dist[u] + w;
                    parent[v] = u;
                }
            }
        }
        bool cycles = false;
        int start = 0;
        for (auto &e : edges)
        {
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if (dist[v] > dist[u] + w)
            {
                cycles = true;
                start = u;
                break;
            }
        }
        if (!cycles)
        {
            cout << "NO" << endl;
            return;
        }
        int x = start;
        for (int i = 1; i < n; i++)
        {
            x = parent[x];
        }
        vector<int> cycle;
        int tmp = x;
        while (true)
        {
            cycle.push_back(x);
            x = parent[x];
            if (x == tmp)
            {
                cycle.push_back(x);
                break;
            }
        }
        reverse(all(cycle));
        cout << "YES" << endl;
        for (int i : cycle)
        {
            cout << i + 1 << " ";
        }
        return;
    }
};

ostream &operator<<(ostream &os, const graph g)
{
    for (int i = 0; i < g.n; i++)
    {
        os << i + 1 << " is adjacent to : ";
        for (auto &e : g.nodes[i].edges)
        {
            os << e.v + 1 << " ";
        }
        os << endl;
    }
    return os;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.add_edge(u, v, w);
    }
    g.BellmanFord(0);

    return 0;
}