#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long

struct edge
{
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
    vector<node> nodes[2];
    int n;
    graph(int _n) : n(_n)
    {
        nodes[0].resize(n);
        nodes[1].resize(n);
    }

    void add_edge(int u, int v)
    {
        nodes[0][u].edges.emplace_back(u, v);
        nodes[1][v].edges.emplace_back(v, u);
    }

    void scc_dfs1(int v, vector<bool> &used, vector<int> &order)
    {
        used[v] = true;
        for (auto &x : nodes[0][v].edges)
            if (!used[x.v])
            {
                scc_dfs1(x.v, used, order);
            }
        order.push_back(v);
    }

    void scc_dfs2(int v, vector<bool> &used, vector<int> &component)
    {
        used[v] = true;
        component.push_back(v);
        for (auto &x : nodes[1][v].edges)
            if (!used[x.v])
            {
                scc_dfs2(x.v, used, component);
            }
    }

    vector<vector<int>> SCC(vector<int> &where)
    {

        vector<bool> used(n, false);
        vector<int> order, component;
        for (int i = 0; i < n; i++)
            if (!used[i])
            {
                scc_dfs1(i, used, order);
            }
        used.assign(n, false);
        vector<vector<int>> ans;
        int count = 1;
        for (int i = 0; i < n; i++)
        {
            int v = order[n - 1 - i];
            if (!used[v])
            {
                scc_dfs2(v, used, component);
                for (auto &x : component)
                {
                    where[x] = count;
                }
                count++;
                ans.push_back(component);
                component.clear();
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
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        g.add_edge(a, b);
    }
    vector<int> where(n);
    vector<vector<int>> v = g.SCC(where);

    cout << v.size() << endl;
    for (int i = 0; i < n; i++)
    {
        cout << where[i] << " ";
    }
    cout << endl;

    return 0;
}