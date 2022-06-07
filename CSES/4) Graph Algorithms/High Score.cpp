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

    vector<int> BellmanFord(int s)
    {
        vector<int> dist(n, INF);
        vector<bool> visited(n, false);
        dist[s] = 0;
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
                }
            }
        }
        bool neg = false;
        for (auto &e : edges)
        {
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if (dist[v] > dist[u] + w)
            {
                vector<bool> vis(n, false);
                if (dfs_check(0, v, vis))
                {
                    dist[v] = (-INF);
                    if (!visited[v])
                    {
                        DFS_for_BF(v, visited, dist);
                    }
                    neg = true;
                }
            }
        }
        return dist;
    }
    void DFS_for_BF(int u, vector<bool> &visited, vector<int> &dist)
    {
        visited[u] = true;
        for (auto &e : nodes[u].edges)
        {
            if (!visited[e.v])
            {
                dist[e.v] = -INF;
                DFS_for_BF(e.v, visited, dist);
            }
        }
    }
    // checks if v is reachable from 0.
    bool dfs_check(int u, int v, vector<bool> &vis)
    {
        vis[u] = true;
        if (u == v)
        {
            return true;
        }
        bool ans = false;
        for (auto &e : nodes[u].edges)
        {
            if (!vis[e.v])
            {
                ans = ans || dfs_check(e.v, v, vis);
            }
        }
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    graph g_mod(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g.add_edge(u, v, w);
        g_mod.add_edge(u, v, -w);
    }
    vector<int> dist = g.BellmanFord(0);
    vector<int> dist_mod = g_mod.BellmanFord(0);

    if (dist_mod[n - 1] == (-INF))
    {
        // i.e node n-1 is contained in a positive weight cycle in original graph and hence we can get any score we want
        cout << -1 << endl;
    }
    else
    {
        // i.e n-1 is NOT contained in a positive weight cycle in original graph
        // now dist_mod[n - 1] is the shortest path from node 0 to n-1 in the negated graph.
        // Since n-1 is NOT contained in a negative weight cycle in the negated graph, hence we can safely negate this weight
        // and get the longest path from 0 to n-1 in original graph
        cout << (-dist_mod[n - 1]) << endl;
    }

    return 0;
}