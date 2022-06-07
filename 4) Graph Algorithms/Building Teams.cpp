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
    vector<edge> edges;
    int color = -1;
};

struct graph
{
    vector<node> nodes;
    int n;
    vector<edge> edges;
    graph(int _n) : n(_n) { nodes.resize(n); }

    void add_edge(int u, int v)
    {
        edge e(u, v);
        edge ep(v, u);
        nodes[u].edges.push_back(e);
        // add if undirected.
        nodes[v].edges.push_back(ep);
        edges.push_back(ep);
        edges.push_back(e);
    }
    bool two_color()
    {
        bool is = true;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++)
        {
            if (nodes[i].color == -1 && !visited[i])
            {
                is = is & DFS(i, visited);
            }
        }
        return is;
    }
    bool DFS(int u, vector<bool> &visited)
    {
        visited[u] = true;
        if (nodes[u].color == -1)
        {
            nodes[u].color = 1;
        }
        bool ans = true;
        for (auto &e : nodes[u].edges)
        {
            if (nodes[e.v].color == nodes[u].color)
            {
                return false;
            }
            if (nodes[e.v].color == -1)
            {
                nodes[e.v].color = (nodes[u].color == 1 ? 2 : 1);
            }
            if (!visited[e.v])
            {
                visited[e.v] = true;
                ans = ans & DFS(e.v, visited);
            }
        }
        return ans;
    }
};

ostream &operator<<(ostream &os, const graph g)
{
    for (int i = 0; i < g.n; i++)
    {
        os << i << " is adjacent to : ";
        for (auto &e : g.nodes[i].edges)
        {
            os << e.v << " ";
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
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
    }
    bool is = g.two_color();
    if (!is)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cout << g.nodes[i].color << " ";
        }
    }

    return 0;
}