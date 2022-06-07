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
        //  nodes[v].edges.push_back(ep);
        // edges.push_back(ep);
        edges.push_back(e);
    }

    vector<int> KhanAlgo()
    {
        vector<int> indegree(n, 0);
        vector<int> res;
        for (auto &e : edges)
        {
            indegree[e.v]++;
        }
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            int curr = q.front();
            q.pop();
            res.push_back(curr);
            for (auto &e : nodes[curr].edges)
            {
                indegree[e.v]--;
                if (indegree[e.v] == 0)
                {
                    q.push(e.v);
                }
            }
        }
        if ((int)res.size() < n)
        {
            return {};
        }
        return res;
    }

    vector<int> Top_Sort_DFS()
    {
        vector<int> order;
        vector<int> color(n, 0);
        bool flag = false;
        for (int i = 0; i < n; i++)
        {
            if (color[i] == 0)
            {
                dfs_util(i, order, flag, color);
            }
        }
        if (flag)
        {
            return {};
        }
        reverse(all(order));
        return order;
    }
    void dfs_util(int u, vector<int> &order, bool &flag, vector<int> &color)
    {
        color[u] = 1;
        for (auto &e : nodes[u].edges)
        {
            if (color[e.v] == 0)
            {
                dfs_util(e.v, order, flag, color);
            }
            if (color[e.v] == 1)
            {
                flag = true;
            }
        }
        color[u] = 2;
        order.push_back(u);
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
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
    }
    vector<int> ans = g.Top_Sort_DFS();
    if ((int)ans.size() == 0)
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int i : ans)
        {
            cout << i + 1 << " ";
        }
    }

    return 0;
}