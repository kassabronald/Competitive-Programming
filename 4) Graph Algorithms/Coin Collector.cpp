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
    int enter_;
    int exit_;
    int c;
    int comp;
    vector<edge> edges;
    vector<edge> incoming;
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
        nodes[v].incoming.push_back(e);
    }

    vector<vector<int>> SCC()
    {
        vector<bool> visited(n, false);
        vector<int> order;
        int time_ = 0;
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs_util(i, visited, order, time_);
            }
        }
        reverse(all(order));
        vector<vector<int>> components;
        dfs_on_transpose(order, components);
        return components;
    }
    void dfs_util(int u, vector<bool> &visited, vector<int> &order, int &time_)
    {
        time_++;
        visited[u] = true;
        nodes[u].enter_ = time_;
        for (auto &e : nodes[u].edges)
        {
            if (!visited[e.v])
            {
                dfs_util(e.v, visited, order, time_);
            }
        }
        time_++;
        nodes[u].exit_ = time_;
        order.push_back(u);
    }

    void dfs_on_transpose(vector<int> &order, vector<vector<int>> &components)
    {
        graph g_t = transpose();
        vector<bool> visited(n, false);
        for (int i : order)
        {
            if (!visited[i])
            {
                vector<int> tmp;
                dfs_util_on_transpose(i, visited, tmp, g_t);
                components.push_back(tmp);
            }
        }
    }

    void dfs_util_on_transpose(int u, vector<bool> &visited, vector<int> &tmp, graph &g_t)
    {
        visited[u] = true;
        tmp.push_back(u);

        for (auto &e : g_t.nodes[u].edges)
        {
            if (!visited[e.v])
            {
                dfs_util_on_transpose(e.v, visited, tmp, g_t);
            }
        }
    }
    graph transpose()
    {
        graph g_t(n);
        for (auto &e : edges)
        {
            g_t.add_edge(e.v, e.u);
        }
        return g_t;
    }
    int compute()
    {
        vector<int> indegree(n, 0);
        vector<int> dp(n, 0);
        // dp[v] := maximum loot if we finish at node v.
        //        = max(dp[u]/ (u, v) in E) + v.c

        int ans = 0;
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
            for (auto &e : nodes[curr].edges)
            {
                indegree[e.v]--;
                if (indegree[e.v] == 0)
                {
                    q.push(e.v);
                }
            }
            dp[curr] = nodes[curr].c;
            int maxx = 0;
            for (auto &e : nodes[curr].incoming)
            {
                maxx = max(maxx, dp[e.u]);
            }
            dp[curr] += maxx;
            ans = max(ans, dp[curr]);
        }
        return ans;
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
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    graph g(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        g.nodes[i].c = k;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g.add_edge(u, v);
    }
    vector<vector<int>> components = g.SCC();
    graph g_comp((int)components.size());
    int i = 0;
    for (vector<int> v : components)
    {
        for (int j : v)
        {
            g.nodes[j].comp = i;
            g_comp.nodes[i].c += (g.nodes[j].c);
        }
        i++;
    }
    for (auto &e : g.edges)
    {
        if (g.nodes[e.u].comp != g.nodes[e.v].comp)
        {
            g_comp.add_edge(g.nodes[e.u].comp, g.nodes[e.v].comp);
        }
    }
    cout << g_comp.compute() << endl;

    cin.ignore(2);
    return 0;
}