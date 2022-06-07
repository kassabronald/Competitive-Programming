#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

#define int long long

struct DSU
{

    map<int, vector<int>> SETS;
    vector<int> representative;
    DSU(int n)
    {
        representative.resize(n);
    }

    void make_set(int x)
    {
        vector<int> vec = {x};
        SETS[x] = vec;
        representative[x] = x;
    }
    int find_set(int y)
    {
        return representative[y];
    }
    int size(int u)
    {
        return SETS[find_set(u)].size();
    }
    void merge(int x, int y)
    {
        int sx = size(x);
        int sy = size(y);

        if (sx < sy)
        {
            int tmp = find_set(x);
            for (int i : SETS[find_set(x)])
            {
                SETS[find_set(y)].push_back(i);
                representative[i] = find_set(y);
            }

            SETS.erase(tmp);
        }
        else
        {

            int tmp = find_set(y);
            for (int i : SETS[find_set(y)])
            {
                SETS[find_set(x)].push_back(i);
                representative[i] = find_set(x);
            }
            SETS.erase(tmp);
        }
    }
};

struct edge
{
    int u, v;
    ll w;
    edge() {}
    edge(int _u, int _v, ll _w) : u(_u), v(_v), w(_w) {}
    bool operator<(const edge &rhs) const { return w < rhs.w; }
};

void print_edge(vector<edge> vec)
{
    for (edge e : vec)
    {
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
}

struct node
{
    vector<edge> edges;
};

struct graph
{
    vector<node> nodes;
    int n = 0;
    vector<edge> edges;
    int m = 0;
    graph(int _n) : n(_n), nodes(_n) {}

    void add_edge(int u, int v, ll w)
    {
        nodes[u].edges.emplace_back(u, v, w);
        nodes[v].edges.emplace_back(v, u, w);
        edges.emplace_back(u, v, w);
        m++;
    }

    vector<edge> KruskalMST()
    {
        DSU dsu(n);
        for (int i = 0; i < n; i++)
        {
            dsu.make_set(i);
        }
        vector<edge> res;
        sort(edges.begin(), edges.end());
        for (edge &e : edges)
        {
            if (dsu.find_set(e.u) != dsu.find_set(e.v))
            {

                dsu.merge(e.u, e.v);
                res.push_back(e);
            }
        }
        return ((int)res.size() == n - 1) ? res : vector<edge>();
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    DSU dsu(n);
    for (int i = 0; i < n; i++)
    {
        dsu.make_set(i);
    }
    int comp = n;
    int maxx = 1;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (dsu.find_set(a) != dsu.find_set(b))
        {
            dsu.merge(a, b);
            comp--;
        }
        maxx = max(maxx, dsu.size(a));
        cout << comp << " " << maxx << endl;
    }

    return 0;
}